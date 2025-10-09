#include "include/clock.h"

void demo_macro_usage() {
    printf("=== 使用宏定义简化计时 ===\n");
    
    TIME_START(计算循环)
    for (long i = 0; i < 50000000; i++) {
        // 一些计算
    }
    TIME_END(计算循环)
}

int main() {
    printf("C语言代码执行时间统计示例\n");
    printf("================================\n\n");
    
    method1_clock();
    method2_time();
    method3_gettimeofday();
    method4_clock_gettime();
    demo_macro_usage();
    
    printf("\n推荐使用方法:\n");
    printf("- 测量CPU时间: clock()\n");
    printf("- 测量实际时间(高精度): clock_gettime() 或 gettimeofday()\n");
    printf("- Linux编译: gcc -o time_test time_test.c\n");
    printf("- 需要链接实时库: gcc -o time_test time_test.c -lrt (某些系统)\n");
    
    return 0;
}