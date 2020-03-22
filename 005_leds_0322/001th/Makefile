all:
	arm-linux-gnueabi-gcc -c -o led.o led.c
	arm-linux-gnueabi-gcc -c -o start.o start.S
	arm-linux-gnueabi-ld -Ttext 0 start.o led.o -o led.elf
	arm-linux-gnueabi-objcopy -O binary -S led.elf led.bin
	arm-linux-gnueabi-objdump -D led.elf > led.dis
clean:
	rm *.bin *.o *.elf *.dis