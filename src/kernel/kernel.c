// Unx Kernel wrote by Huguini79 (https://github.com/Huguini79)

#include "kernel.h"
#include "vga/vga.h"
#include "keyboard/keyboard.h"

int init_kernel = 0;

const char* message = "                                                                                                             Press ALT to boot";

void kernel_main() {
	init_vga_screen();
	init_kernel = 1;
	for(int y = 0; y < VGA_HEIGHT; y++) {
		for(int x = 0; x < VGA_WIDTH; x++) {
			terminal_putchar(x, y, ' ', 0);
		}
	}
	for(int iini = 0; iini < 30; iini++) {
		terminal_writechar(' ', 0);
	}
	for(int iini2 = 0; iini2 < 5; iini2++) {
		terminal_writechar('\n', 0);
	}
	for(int iini3 = 0; iini3 < 36; iini3++) {
		terminal_writechar(' ', 0);
	}
	terminal_writechar('U', 15);
	terminal_writechar('n', 15);
	terminal_writechar('x', 15);

	terminal_writechar('\n', 15);

	size_t len = strlen(message);

	for(int i = 0; i < len; i++) {
		terminal_writechar(message[i], 15);
	}

	init_keyboard();
}
