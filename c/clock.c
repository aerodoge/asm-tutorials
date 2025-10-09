#include "include/clock.h"


void am_clock() {
    printf("=== clock() - CPU时间 ===\n");
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // 你要测试的代码
    for (long i = 0; i < 100000000; i++) {
        // 模拟一些计算
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU时间: %f 秒\n\n", cpu_time_used);
}

void am_time() {
    printf("=== time() - 实际时间（秒级） ===\n");
    time_t start, end;
    double elapsed;
    start = time(NULL);
    
    // 你要测试的代码

    sleep(2); // 睡眠2秒作为演示
    end = time(NULL);
    elapsed = difftime(end, start);
    printf("实际时间: %.0f 秒\n\n", elapsed);
}

void am_gettimeofday() {
    printf("=== gettimeofday() - 高精度实际时间 ===\n");
    struct timeval start, end;
    long seconds, useconds;
    double elapsed;
    gettimeofday(&start, NULL);

    // 你要测试的代码
    for (long i = 0; i < 100000000; i++) {
        // 模拟一些计算
    }

    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    elapsed = seconds + useconds / 1000000.0;
    printf("实际时间: %f 秒\n", elapsed);
    printf("实际时间: %ld 微秒\n\n", seconds * 1000000 + useconds);
}

void am_clock_gettime() {
    printf("=== clock_gettime() - 纳秒级精度 ===\n");
    struct timespec start, end;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // 你要测试的代码
    for (long i = 0; i < 100000000; i++) {
        // 模拟一些计算
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec);
    elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("实际时间: %f 秒\n", elapsed);
    printf("实际时间: %ld 纳秒\n\n", 
           (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec));
}





