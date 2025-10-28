# Clear the screen
clear

# Compile assembly files
nasm -f elf32 src/kernel/kernel.asm -o build/kernel.asm.o
nasm -f elf32 src/io/io.asm -o build/io.asm.o
nasm -f elf32 src/gdt/gdt.asm -o build/gdt.asm.o
nasm -f elf32 src/task/tss.asm -o build/tss.asm.o

# Compile C files
gcc -I./src -m32 -ffreestanding -nostdlib -c src/kernel/kernel.c -o build/kernel.o
gcc -I./src -m32 -ffreestanding -nostdlib -c src/vga/vga.c -o build/vga.o
gcc -I./src -m32 -ffreestanding -nostdlib -c src/keyboard/keyboard.c -o build/keyboard.o
gcc -I./src -m32 -ffreestanding -nostdlib -c src/gdt/gdt.c -o build/gdt.o

# Use the linker to put all the object files in one elf_i386 kernel file
ld -m elf_i386 -T src/linker/linker.ld -o iso/boot/kernel build/kernel.asm.o build/io.asm.o build/kernel.o build/vga.o build/keyboard.o build/gdt.asm.o build/gdt.o build/tss.asm.o

# Call grub to make the iso (make sure yo have installed xorriso)
grub-mkrescue -o bin/Unx.iso iso

# Finally, test our kernel with QEMU (you can also run the kernel in other virtual machines or in real hardware, thanks to GRUB)
qemu-system-x86_64 -m 1024 bin/Unx.iso
