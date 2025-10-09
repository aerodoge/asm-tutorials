#include "include/clock.h"

struct data_t {
    char padding[63];
    int counter;
};

int main() {
    struct data_t counter = {.padding="Hello",.counter=0};
    
    struct timespec start, end;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // 锁总线
    for(int i = 0; i < 1000000; i++) {
        __sync_fetch_and_add(&counter.counter, 1);  // LOCK XADD
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec);
    elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("实际时间: %f 秒\n", elapsed);
    printf("实际时间: %ld 纳秒\n\n", 
           (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec));

    return 0;
}


