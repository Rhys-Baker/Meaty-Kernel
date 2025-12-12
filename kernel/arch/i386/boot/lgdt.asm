[BITS 32]

global load_gdt

section .data
gdtr:
dw      0 ; For limit storage
dd      0 ; For limit storage

section .text
; void load_gdt(uint16_t limit, uint32_t base);
load_gdt:
    ; Store limit
    mov     ax, [esp + 4]
    mov     [gdtr], ax
    ; Store base
    mov     eax, [esp + 8]
    ; add   eax, [ESP + 12] ; if including offset for non-flat models
    mov     [gdtr + 2], eax
    ; Load gdt and return
    lgdt    [gdtr]
    ret

