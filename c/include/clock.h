#ifndef ATOMIC_MUTEX_H
#define ATOMIC_MUTEX_H

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define TIME_START(label) \
    struct timespec _time_start_##label, _time_end_##label; \
    clock_gettime(CLOCK_MONOTONIC, &_time_start_##label);

#define TIME_END(label) \
    clock_gettime(CLOCK_MONOTONIC, &_time_end_##label); \
    printf("%s 执行时间: %.6f 秒\n", #label, \
           (_time_end_##label.tv_sec - _time_start_##label.tv_sec) + \
           (_time_end_##label.tv_nsec - _time_start_##label.tv_nsec) / 1000000000.0);

void am_clock();
void am_time();
void am_gettimeofday();
void am_clock_gettime();


#endif


