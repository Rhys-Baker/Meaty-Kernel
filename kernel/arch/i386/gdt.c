#include <kernel/gdt.h>
#include <stdio.h>

uint8_t gdt[5][8];

void encode_gdt_entry(uint8_t *target, GDTEntry source){
    if(source.limit > 0xFFFFF) {
        // GDT cannot encode limits larger than 0xFFFFF
        printf("\x1B\x0C""E: GDT cannot encode limits larger than 0xFFFFF\x1B\x0F\n");
        return;
    }

    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] = (source.limit >> 16) & 0x0F;

    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;

    target[5] = source.access_byte;
    
    target[6] |= (source.flags << 4);
}

void init_gdt(void){
    GDTEntry null_descriptor = {
        .base = 0x00,
        .limit = 0x00,
        .access_byte = 0x00,
        .flags = 0x00
    };
    GDTEntry kernel_mode_code_segment = {
        .base  = 0x00000000,
        .limit = 0xFFFFF,
        .access_byte = 0x9A,
        .flags = 0x0C
    };
    GDTEntry kernel_mode_data_segment = {
        .base  = 0x00000000,
        .limit = 0xFFFFF,
        .access_byte = 0x92,
        .flags = 0x0C
    };

    asm volatile("cli");
    
    encode_gdt_entry(gdt[0], null_descriptor);
    encode_gdt_entry(gdt[1], kernel_mode_code_segment);
    encode_gdt_entry(gdt[2], kernel_mode_data_segment);

    uint16_t limit = sizeof(gdt) - 1;
    uint32_t base = (uint32_t)&gdt;
    
    load_gdt(limit, base);

    reload_segments();
}
