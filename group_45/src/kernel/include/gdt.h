#ifndef GDT_H
#define GDT_H

#include <stdint.h>

#define GDT_ENTRIES 5


struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr
{
    uint16_t limit;
    uint32_t base;
 
} __attribute__((packed));


void init_gdt();
void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

struct gdt_entry gdt[GDT_ENTRIES];
struct gdt_ptr gdt_ptr;


#endif