// Unx VGA Driver wrote by Huguini79 (https://github.com/Huguini79)

#include "vga.h"

#include <stdint.h>
#include <stddef.h>

// Define the VGA struct
struct vga_struct* vga;

// Define VGA Row (height) (y)
uint16_t terminal_row = 0;

// Define VGA_COL (width) (x)
uint16_t terminal_col = 0;

// Define terminal_make_char function
uint16_t terminal_make_char(char c, char colour) {
	return (colour << 8) | c;
}

// Define terminal_putchar function
void terminal_putchar(int x, int y, char c, char colour) {
	vga->video_mem[(y * VGA_WIDTH) + x] = terminal_make_char(c, colour); // Write into
}

// Define terminal_writechar function
void terminal_writechar(char c, char colour) {
	if(c == '\n') { // Check the input contains \n
		terminal_row += 1; // Move the cursor down
		terminal_col = 0; // Move the cursor to the left
	}

	vga->terminal_row = terminal_row; // Put the terminal_row variable into vga->terminal_row variable
	vga->terminal_col = terminal_col; // Put the terminal_col variable into vga->terminal_col variable

	terminal_putchar(vga->terminal_col, vga->terminal_row, c, colour); // Write in VGA Video Mem
	terminal_col += 1; // Move the cursor to the right

	vga->terminal_col = terminal_col; // Put the terminal_col variable into vga->terminal_col variable

	if(vga->terminal_col >= VGA_WIDTH) {
		terminal_row += 1; // Move the cursor down
		terminal_col = 0; // Move the cursor to the left
	}
	
	if(vga->terminal_row >= VGA_HEIGHT) {
		clear(); // Clear the screen
	}

	vga->terminal_row = terminal_row; // Put the terminal_row variable into the vga->terminal_row variable
	vga->terminal_col = terminal_col; // Put the terminal_col variable into vga->terminal_col variable

}

// Define the init_vga_screen function
void init_vga_screen() {
	vga->video_mem = (uint16_t*)(0xB8000); // Define the VGA Address (0xB8000)
	terminal_row = 0; // Move the cursor to the top
	terminal_col = 0; // Move the cursor to the left

	fill_screen_with_blue(); // Clear the screen

}

// Define the fill_screen_with_blue function
void fill_screen_with_blue() {
	// Fill all the screen with blue

	for(int y = 0; y < VGA_HEIGHT; y++) {
		for(int x = 0; x < VGA_WIDTH; x++) {
			terminal_putchar(x, y, ' ', 0x1F);
		}
	}

}

// Define the size_t strlen function
size_t strlen(const char* str) {
	size_t len = 0; // Define len variable

	while(str[len]) {
		len++; // Increment len variable
	}

	return len; // Return the len variable (size of the const char* variable)

}

// Define the printx function
void printx(const char* str) {
	size_t len = strlen(str); // Get the size of const char* str variable

	for(int i = 0; i < len; i++) { // With the size of the const char* str variable, we are going to print all the words of the str variable with the terminal_writechar function
		terminal_writechar(str[i], 0x2F);
	}

}

// Define the clear function
void clear() {
	// Clear the screen and fill it with blue
	terminal_row = 0; // Go to the top
	terminal_col = 0; // Go to the left

	vga->terminal_row = terminal_row; // Put terminal_row variable into vga->terminal_row variable
	vga->terminal_col = terminal_col; // Put terminal_col variable into vga->terminal_col variable

	// Fill the screen with blue

	fill_screen_with_blue();
	
	printx("Welcome to Unx Kernel - Huguini79                                               ");
	for(int i = 0; i < 80; i++) {
		terminal_writechar(' ', 0x1F);
	}
	terminal_writechar('\n', 0x4F);
	terminal_writechar('u', 0x4F);
	terminal_writechar('n', 0x4F);
	terminal_writechar('x', 0x4F);
	terminal_writechar('>', 0x4F);
	terminal_writechar(' ', 0x4F);

}
