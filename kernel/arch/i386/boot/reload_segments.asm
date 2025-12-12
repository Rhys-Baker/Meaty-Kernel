[BITS 32]

global reload_segments

section .text

reload_segments:
    ; Reload CS register containing code selector
    jmp 0x08:.reload_cs ; 0x08 is a stand-in for the code segment
.reload_cs:
    ; Reload the data segment registers
    mov ax, 0x10 ; Stand-in for the data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret
