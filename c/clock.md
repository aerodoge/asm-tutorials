## 各方法的特点
* clock() - 测量CPU时间
    * 精度：微秒到毫秒级
    * 只统计CPU执行时间，不包括sleep等待时间
    * 适合测量纯计算代码
* time() - 秒级精度
    * 精度：秒级
    * 测量实际经过的时间
    * 适合长时间运行的代码
* gettimeofday() - 微秒级精度
    * 精度：微秒级
    * 测量实际经过的时间
    * 跨平台兼容性好
* clock_gettime() - 纳秒级精度
    * 精度：纳秒级（最高）
    * POSIX标准，推荐使用
    * 需要链接 -lrt 库（某些系统）

## 编译命令
```
bashgcc -o time_test time_test.c
# 或者需要链接实时库
gcc -o time_test time_test.c -lrt
```

## 使用建议
* 纯计算代码：使用 clock()
* 包含I/O或系统调用：使用 clock_gettime() 或 gettimeofday()
* 需要最高精度：使用 clock_gettime()


