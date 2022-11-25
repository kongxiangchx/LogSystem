#ifndef __CHX_UTIL_H__
#define __CHX_UTIL_H__

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>

namespace chx {

pid_t GetThreadId();
uint32_t GetFiberId();

}

#endif