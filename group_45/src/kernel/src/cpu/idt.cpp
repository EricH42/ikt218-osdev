#include "idt.h"

extern "C" {
   extern void idt_flush(uint32_t);
}

void init_idt() {
  // Set the IDT limit
  idt_ptr.limit = sizeof(struct idt_entry) * IDT_ENTRIES - 1;
  idt_ptr.base = (uint32_t) &idt;

  // 1. Initialize all IDT entries to the default interrupt handler
  for (int i = 0; i < IDT_ENTRIES; i++) {
    idt[i].base_low = 0x0000;
    idt[i].base_high = 0x0000;
    idt[i].zero = 0x00;
    idt[i].flags = 0x8E;
  }

  // Load the IDT
  idt_flush((uint32_t)&idt_ptr);
}

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
    idt[num].base_low = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;

    idt[num].selector     = sel;
    idt[num].zero = 0;
    idt[num].flags   = flags  | 0x60;
}