#include "util.h"

namespace chx {

pid_t GetThreadId() {
    return syscall(SYS_gettid);
}

uint32_t GetFiberId() {
    return 0;
}

size_t GetFileSize(const char* filename) {
    if(filename == nullptr) {
        return 0;
    }
    struct stat statbuf;
    stat(filename, &statbuf);
    return statbuf.st_size;
}

}