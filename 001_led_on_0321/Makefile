all:
	arm-linux-gnueabi-gcc -c -o led_on.o led_on.S
	arm-linux-gnueabi-ld -Ttext 0 led_on.o -o led_on.elf
	arm-linux-gnueabi-objcopy -O binary -S led_on.elf led_on.bin
	arm-linux-gnueabi-objdump -D led_on.elf > led_on.dis
clean:
	rm *.bin *.o *.elf