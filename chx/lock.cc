#include "lock.h"
#include <unistd.h>

#define spinMaxCnt 10

namespace chx {

void SpinLock::lock() {
    uint32_t cnt = 0;
    while(flag.test_and_set(std::memory_order_acquire)) {
        cnt++;
        if(cnt >= spinMaxCnt) {
            cnt = 0;
            sleep(0);
        }
    }
}
void SpinLock::unlock() {
    flag.clear(std::memory_order_release);
}

void RWLock::readLock() {
    std::unique_lock<std::mutex> lock(mx);
    ++readWaiting;
    cond.wait(lock, [&]()->bool {
        return writing <= 0 && (!preferWriter || writeWaiting <= 0);
    });
    ++reading;
    --readWaiting;
}

void RWLock::writeLock() {
    std::unique_lock<std::mutex> lock(mx);
    ++writeWaiting;
    cond.wait(lock, [&]()->bool {
        return reading <= 0 && writing <= 0;
    });
    ++writing;
    --writeWaiting;
}

void RWLock::readUnLock() {
    std::unique_lock<std::mutex> lock(mx);
    --reading;
    if(reading <= 0) {
        cond.notify_one();
    }
}

void RWLock::writeUnLock() {
    std::unique_lock<std::mutex> lock(mx);
    --writing;
    cond.notify_all();
}

}