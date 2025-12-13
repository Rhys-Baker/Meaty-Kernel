[BITS 32]

global load_idt

section .data
idtr:
dw      0 ; For limit storage
dd      0 ; For base storage

section .text
; void load_idt(uint16_t limit, uint32_t base);
load_idt:
    ; Store limit
    mov     ax, [esp + 4]
    mov     [idtr], ax
    ; Store base
    mov     eax, [esp + 8]
    mov     [idtr + 2], eax
    ; Load gdt and return
    lidt    [idtr]
    ret

