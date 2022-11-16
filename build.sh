mkdir build

i686-elf-as src/boot.s -o build/boot.o
i686-elf-g++ src/kernel.cpp -c -I include -o build/kernel.o -ffreestanding -fno-rtti -g
i686-elf-g++ src/libcpp.cpp -c -I include -o build/libcpp.o -ffreestanding -fno-rtti -g
i686-elf-g++ src/terminal.cpp -c -I include -o build/terminal.o -ffreestanding -fno-rtti -g
i686-elf-g++ src/string.cpp -c -I include -o build/string.o -ffreestanding -fno-rtti -g
i686-elf-g++ src/memory.cpp -c -I include -o build/memory.o -ffreestanding -fno-rtti -g
i686-elf-g++ src/main.cpp -c -I include -o build/main.o -ffreestanding -fno-rtti -g
i686-elf-g++ src/libmem.cpp -c -I include -o build/libmem.o -ffreestanding -fno-rtti -g
i686-elf-g++ src/vector.cpp -c -I include -o build/vector.o -ffreestanding -fno-rtti -g

i686-elf-g++ -T linker.ld -o build/my-os.bin -ffreestanding -nostdlib build/boot.o build/libcpp.o build/kernel.o build/terminal.o build/string.o build/memory.o build/main.o build/libmem.o build/vector.o -lgcc

cp build/my-os.bin isodir/boot/my-os.bin
grub-mkrescue -o build/my-os.iso isodir 