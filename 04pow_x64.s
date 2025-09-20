# 64位模式使用不同的寄存器（%rax、%rbx 等代替 %eax、%ebx）、调用约定和系统调用号（syscall代替int $0x80）


# 计算 3^2 + 2^5
.section .data
.section .text

.globl _start

_start:
    pushq $2
    pushq $3
    call power
    addq $16, %rsp
    pushq %rax

    pushq $5
    pushq $2
    call power
    addq $16, %rsp

    popq %rbx
    addq %rax, %rbx
    movq $60, %rax  # 64位系统调用号：60 为 exit
    movq %rbx, %rdi # 退出状态码
    syscall

.type power, @function
power:
    pushq %rbp
    movq %rsp, %rbp
    subq $8, %rsp
    movq 16(%rbp), %rbx  # 底数
    movq 24(%rbp), %rcx  # 指数
    movq %rbx, -8(%rbp)

    cmpq $0, %rcx
    jne power_loop_start
    movq $1, %rax
    jmp end_power

power_loop_start:
    cmpq $1, %rcx
    je end_power
    movq -8(%rbp), %rax
    imulq %rbx, %rax
    movq %rax, -8(%rbp)
    decq %rcx
    jmp power_loop_start

end_power:
    movq -8(%rbp), %rax
    movq %rbp, %rsp
    popq %rbp
    ret

