// Unx Kernel wrote by Huguini79 (https://github.com/Huguini79)

#include "kernel.h"
#include "vga/vga.h"
#include "keyboard/keyboard.h"

void kernel_main() {
	init_vga_screen();
	printx("Welcome to Unx Kernel - Huguini79                                               ");
	for(int i = 0; i < 80; i++) {
		terminal_writechar(' ', 0x1F);
	}
	terminal_writechar('u', 0x4F);
	terminal_writechar('n', 0x4F);
	terminal_writechar('x', 0x4F);
	terminal_writechar('>', 0x4F);
	terminal_writechar(' ', 0x4F);
	init_keyboard();
}
