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

void say_unx() {
	terminal_writechar('\n', 0x1F);
	terminal_writechar('u', 0x4F);
	terminal_writechar('n', 0x4F);
	terminal_writechar('x', 0x4F);
	terminal_writechar('>', 0x4F);
	terminal_writechar(' ', 0x4F);
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
			if(scancode == 0x20) { // d
				printx("d");
				add_character('d');
			}
			if(scancode == 0x12) { // e
				printx("e");
				add_character('e');
			}
			if(scancode == 0x21) { // f
				printx("f");
				add_character('f');
			}
			if(scancode == 0x22) { // g
				printx("g");
				add_character('g');
			}
			if(scancode == 0x23) { // h
				printx("h");
				add_character('h');
			}
			if(scancode == 0x17) { // i
				printx("i");
				add_character('i');
			}
			if(scancode == 0x24) { // j
				printx("j");
				add_character('j');
			}
			if(scancode == 	0x25) { // k
				printx("k");
				add_character('k');
			}
			if(scancode == 0x26) { // l
				printx("l");
				add_character('l');
			}
			if(scancode == 0x32) { // m
				printx("m");
				add_character('m');
			}
			if(scancode == 0x31) { // n
				printx("n");
				add_character('n');
			}
			if(scancode == 0x18) { // o
				printx("o");
				add_character('o');
			}
			if(scancode == 0x19) { // p
				printx("p");
				add_character('p');
			}
			if(scancode == 0x10) { // q
				printx("q");
				add_character('q');
			}
			if(scancode == 0x13) { // r
				printx("r");
				add_character('r');
			}
			if(scancode == 0x1F) { // s
				printx("s");
				add_character('s');
			}
			if(scancode == 0x14) { // t
				printx("t");
				add_character('t');
			}
			if(scancode == 0x16) { // u
				printx("u");
				add_character('u');
			}
			if(scancode == 0x2F) { // v
				printx("v");
				add_character('v');
			}
			if(scancode == 0x11) { // w
				printx("w");
				add_character('w');
			}
			if(scancode == 0x2D) { // x
				printx("x");
				add_character('x');
			}
			if(scancode == 0x15) { // y
				printx("y");
				add_character('y');
			}
			if(scancode == 0x2C) { // z
				printx("z");
				add_character('z');
			}
			if(scancode == 0x39) { // SPACE
				printx(" ");
				add_character(' ');
			}
			if(scancode == 0x38) { // ALT
				clear(); // Clear the screen
			}
			if(scancode == 0x1C) { // ENTER
				if(strncmp(buffer, "", 1) == 0) {
					say_unx();	
				}
				else if(strncmp(buffer, "unx", 3) == 0) {
					printx("\nWELCOME TO UNX\n");
					say_unx();
					
				}
				else if(strncmp(buffer, "bonus", 5) == 0) {
					clear();
					printx("\nHello, I'm Huguini79, unx is an educational kernel made for people who want to learn how to develop some easy operating systems. I hope this operating system will be very fun, because is open source and you can make your own distributions of unx, this operating system is the best for me, I took the code from my mind, and I want people to learn operating systems very fast, very easy and in a easy and fun way. HAVE FUN!!!!\n");
					say_unx();
				}
				else if(strncmp(buffer, "help", 4) == 0) {
					clear();
					printx("\n");
					for(int i = 0; i < 30; i++) {
						printx("=");
					}
					printx("HELP");
					for(int i2 = 0; i2 < 45; i2++) {
						printx("=");
					}
					printx("\n1) unx - welcome message\n2) bonus - Bonus text\n3) docsvga - Documentation of the VGA driver\n4) docsio - Documentation of the I/O driver\n");
					say_unx();
				}
				else if(strncmp(buffer, "docsvga", 7) == 0) {
					clear();
					printx("\n\n=====================\n====src/vga/vga.h====\n=====================\n\n\nuint16_t terminal_make_char(char c, char colour); // For making a character \nvoid terminal_putchar(int x, int y, char c, char colour); // For putting the generated character by the terminal_make_char() function and then put it in the VGA Video Mem \nvoid terminal_writechar(char c, char colour); // Better implementation than terminal_putchar() \nvoid init_vga_screen(); // Initialize the video mem with the VGA address 0xB8000 \nsize_t strlen(const char* str); // String function to see the size of the words \nvoid printx(const char* str); // Print more words \nvoid clear(); // Clear the screen\n");
					say_unx();
				}
				else if(strncmp(buffer, "docsio", 6) == 0) {
					clear();
					printx("\n\n=====================\n====src/io/io.asm====\n=====================\n\n\nglobal insb\n\ninsb:\npush ebp\nmov ebp, esp\n\nxor eax, eax\nmov edx, [ebp + 8]\nin al, dx\n\npop ebp\nret\n");
					say_unx();
				}
				else {
					printx("\nCOMMAND NOT RECOGNIZED\n");
					say_unx();
				}
				pos = 0;
				buffer[pos] = '\0';
			}
		}

	}
}
