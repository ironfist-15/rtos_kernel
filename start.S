.section .text
.globl _start

_start:
    la sp, stack_top
    call main

halt:
    j halt

.section .bss
.space 4096
stack_top:
