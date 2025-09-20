# 在64位模式下，push和pop指令不需要后缀l，而pushl和popl是32位模式下的指令，因此会报“invalid instruction suffix”错误。
# as --32 04pow_x86.s -o pow.o 
# ld -m elf_i386 pow.o -o pow 
# 
# 在64位Ubuntu系统上运行或编译32位程序需要安装32位支持库
# sudo apt-get update
# sudo apt-get install gcc-multilib

# 计算 $2^3 + 5^2$
.section .data
.section .text

.globl _start


_start:
    pushl $3
    pushl $2
    call power
    addl $8, %esp
    pushl %eax

    pushl $2
    pushl $5
    call power
    addl $8, %esp

    popl %ebx
    addl %eax, %ebx
    movl $1, %eax
    int $0x80

.type power, function
power:
    pushl %ebp
    movl %esp, %ebp
    subl $4, %esp
    movl 8(%ebp), %ebx
    movl 12(%ebp), %ecx
    movl %ebx, -4(%ebp)

power_loop_start:
    cmpl $1, %ecx
    je end_power
    movl -4(%ebp), %eax
    imull %ebx, %eax
    movl %eax, -4(%ebp)

    decl %ecx
    jmp power_loop_start

end_power:
    movl -4(%ebp), %eax
    movl %ebp, %esp
    popl %ebp
    ret


