#include "idt.h"

void init_idt() {
  // Set the IDT limit
  idt_ptr.limit = sizeof(struct idt_entry) * IDT_ENTRIES - 1;
  idt_ptr.base = (uint32_t) &idt;

  // 1. Initialize all IDT entries to the default interrupt handler
	// 2. Initialize all entries in the int_handlers array to NULL
  for (int i = 0; i < IDT_ENTRIES; i++) {
    idt[i].base_low = 0x0000;
    idt[i].base_high = 0x0000;
    idt[i].zero = 0x00;
    idt[i].flags = 0x8E;
  }

  // Load the IDT
  idt_load(&idt_ptr);
}

void idt_load(struct idt_ptr *idt_ptr) {
  // Load the IDT using the LIDT instruction
  asm volatile("lidt %0" : : "m" (*idt_ptr));
}