// Unx Kernel wrote by Huguini79 (https://github.com/Huguini79)

#include "kernel.h"
#include "vga/vga.h"
#include "keyboard/keyboard.h"
#include "gdt/gdt.h"
#include "config.h"
#include "task/tss.h"

int init_kernel = 0;

const char* message = "                                                                                                             Press ALT to boot";

void* memset(void* ptr, int c, size_t size) {
	char* c_ptr = (char*)ptr;

	for(int i = 0; i < size; i++) {
		c_ptr[i] = (char)c;
	}

	return ptr;

}

struct tss tss;
struct gdt gdt_real[UNX_TOTAL_GDT_SEGMENTS];

struct gdt_structured gdt_structured[UNX_TOTAL_GDT_SEGMENTS] = {
{.base = 0x00, .limit = 0x00, .type = 0x00}, // NULL
{.base = 0x00, .limit = 0xffffffff, .type = 0x9a}, // Kernel code segment
{.base = 0x00, .limit = 0xffffffff, .type = 0x92}, // Kernel data segment
{.base = 0x00, .limit = 0xffffffff, .type = 0xf8}, // User
{.base = 0x00, .limit = 0xffffffff, .type=0xf2}, // User
{.base = (uint32_t)&tss, .limit = sizeof(tss), .type=0xE9} // TSS Segment
};

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

	memset(gdt_real, 0x00, sizeof(gdt_real));
	gdt_structured_to_gdt(gdt_real, gdt_structured, UNX_TOTAL_GDT_SEGMENTS);
	gdt_load(gdt_real, sizeof(gdt_real));

	memset(&tss, 0x00, sizeof(tss));
	tss.esp0 = 0x600000;
	tss.ss0 = KERNEL_DATA_SELECTOR;

	tss_load(0x28);

	init_keyboard();
}
