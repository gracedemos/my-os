.set ALIGN,     1<<0
.set MEMINFO,   1<<1
.set FLAGS,     ALIGN | MEMINFO
.set MAGIC,     0x1BADB002
.set CHECKSUM,  -(MAGIC + FLAGS)

.align 4
.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.align 16
    stack_bottom:
        .skip 16384
    stack_top:
        .skip 32
    heap_bottom:
        .skip 16384
    heap_top:

    .section .text
    .global _start

    _start:
        mov $stack_top, %esp
        push $heap_bottom
        call kernelMain

        cli
1:          hlt
        jmp 1b
