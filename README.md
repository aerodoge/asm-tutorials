# ASM Tutorials

在 Ubuntu 上编译汇编程序，主要使用的工具是 GNU 汇编器（as） 和 GNU 链接器（ld），它们都是 GNU Binutils 软件包的一部分，并且通常与 GCC（GNU Compiler Collection） 一起安装。

```
as --version
GNU assembler (GNU Binutils for Ubuntu) 2.42
Copyright (C) 2024 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or later.
This program has absolutely no warranty.
This assembler was configured for a target of `x86_64-linux-gnu'.


ld --version
GNU ld (GNU Binutils for Ubuntu) 2.42
Copyright (C) 2024 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) a later version.
This program has absolutely no warranty.


gcc --version
gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## 编译链接
```
as exits. -o exit.o
ld exit.o -o exit
```

## 开发环境
* Linux平台
    * GNU Assembler(as)
    * 默认语法:`AT&T`
    * 文件后缀:`.s .S`
* Windows平台
    * Microsoft Assembler(MASM)
    * 默认语法:`Intel`
    * 文件后缀:`.asm`

## 说明
本项目主要是Linux汇编，使用AT&T语法，Intel语法会在x86汇编中。



