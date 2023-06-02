#ifndef IDT_H
#define IDT_H
#include <stdint.h>

#define IDT_ENTRIES 256

// Define the IDT entry structure
struct idt_entry {
  uint16_t base_low;
  uint16_t selector;
  uint8_t zero;
  uint8_t flags;
  uint16_t base_high;
} __attribute__((packed));

// Define the GDT and IDT pointers

struct idt_ptr {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed));


void init_idt();
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

struct idt_entry idt[IDT_ENTRIES];
struct idt_ptr idt_ptr;

#endif  