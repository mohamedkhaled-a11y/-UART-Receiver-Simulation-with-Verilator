// startup.s
    .section .text
    .global _start

_start:
    ldr sp, =stack_top     // Set up stack
    bl main                // Branch to main
hang:
    b hang                 // Infinite loop if main returns

    .section .bss
    .space 4096            // Optional BSS section

    .section .stack
    .space 1024
stack_top:
