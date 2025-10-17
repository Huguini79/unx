// Unx keyboard driver wrote by Huguini79 (https://github.com/Huguini79)

#include "keyboard.h"
#include "vga/vga.h"

#define MAX_LENGTH_BUFFER 512

char buffer[MAX_LENGTH_BUFFER];

int pos = 0;

int strncmp(const char* str1, const char* str2, int n)
{
    unsigned char u1, u2;

    while(n-- > 0)
    {
        u1 = (unsigned char)*str1++;
        u2 = (unsigned char)*str2++;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}


void add_character(char c) {
	buffer[pos++] = c;
	buffer[pos] = '\0';
}

void init_keyboard() {
	while(1) {
		uint8_t status = insb(0x64); // Detect keyboard status

		if(status & 0x01) { // Key has been pressed
			uint8_t scancode = insb(0x60);

			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x30) { // b
				printx("b");
				add_character('b');
			}
			if(scancode == 0x2E) { // c
				printx("c");
				add_character('c');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
			if(scancode == 0x1E) { // a
				printx("a");
				add_character('a');
			}
		}

	}
}
