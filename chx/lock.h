#ifndef __CHX_LOCK_H__
#define __CHX_LOCK_H__

#include <mutex>
#include <atomic>
#include <condition_variable>

namespace chx {

class SpinLock {
public:
    typedef std::lock_guard<SpinLock> SpinLockGuard;

    void lock();
    void unlock();

private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
};

template<class T>
class ReadLockImpl {
public:
    ReadLockImpl(T& lock)
        : m_lock(lock) {
        m_lock.readLock();
    }
    ~ReadLockImpl() {
        m_lock.readUnLock();
    }
    void lock() {
        m_lock.readLock();
    }
    void unlock() {
        m_lock.readUnLock();
    }
private:
    T& m_lock;
};

template<class T>
class WriteLockImpl {
public:
    WriteLockImpl(T& lock)
        : m_lock(lock) {
        m_lock.writeLock();
    }
    ~WriteLockImpl() {
        m_lock.writeUnLock();
    }
    void lock() {
        m_lock.writeLock();
    }
    void unlock() {
        m_lock.writeUnLock();
    }
private:
    T& m_lock;
};

class RWLock {
public:
    typedef ReadLockImpl<RWLock> ReadLockGuard;
    typedef WriteLockImpl<RWLock> WriteLockGuard;

    RWLock(bool isPreferWriter = false) 
        : preferWriter(isPreferWriter) {
    }

    void readLock();
    void writeLock();
    void readUnLock();
    void writeUnLock();

private:
    uint32_t readWaiting = 0;
    uint32_t writeWaiting = 0;
    uint32_t reading = 0;
    uint32_t writing = 0;
    std::mutex mx;
    std::condition_variable cond;
    bool preferWriter;
};

}
#endif