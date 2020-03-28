all:
	arm-linux-gnueabi-gcc -c -o led.o led.c
	arm-linux-gnueabi-gcc -c -o uart.o uart.c
	arm-linux-gnueabi-gcc -c -o main.o main.c
	arm-linux-gnueabi-gcc -c -o start.o start.S
	arm-linux-gnueabi-ld -Ttext 0 start.o led.o uart.o main.o -o uart.elf
	arm-linux-gnueabi-objcopy -O binary -S uart.elf uart.bin
	arm-linux-gnueabi-objdump -D uart.elf > uart.dis
clean:
	rm *.bin *.o *.elf *.dis