#include "system.h"

#define VGA_ADDRESS 0xB8000

void clearScreen()
{
    uint8_t *vga = (uint8_t*) VGA_ADDRESS;
    for (int i = 0; i < 2200; i++)
    {
        vga[i] = 0;
    }
}

void write_string(const char *string )
{
    volatile char *video = (volatile char*)VGA_ADDRESS;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = 15;
    }
}


// Define entry point in asm to prevent C++ mangling
extern "C"{
    void kernel_main();
}

void kernel_main()
{
    clearScreen();
    write_string("Hello World");
}