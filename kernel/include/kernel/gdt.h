#pragma once
#include <stdint.h>

typedef struct GDTEntry {
    unsigned int base;
    unsigned int limit;
    uint8_t access_byte;
    uint8_t flags;
} GDTEntry;

extern uint8_t gdt[5][8];

extern void load_gdt(uint16_t limit, uint32_t base);
extern void reload_segments();
void init_gdt(void);
void encode_gdt_entry(uint8_t *target, GDTEntry source);

