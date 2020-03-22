all:
	arm-linux-gnueabi-gcc -c -o key_led.o key_led.c
	arm-linux-gnueabi-gcc -c -o start.o start.S
	arm-linux-gnueabi-ld -Ttext 0 start.o key_led.o -o key_led.elf
	arm-linux-gnueabi-objcopy -O binary -S key_led.elf key_led.bin
	arm-linux-gnueabi-objdump -D key_led.elf > key_led.dis
clean:
	rm *.bin *.o *.elf *.dis