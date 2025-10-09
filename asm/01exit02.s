# 向Linux内核返回一个状态码3
# %eax保存系统调用号
# %ebx保存返回状态
.section .data
.section .text
.globl _start


_start:
    movl $1, %eax
    movl $3, %ebx
    int $0x80
