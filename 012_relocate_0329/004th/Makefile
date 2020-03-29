all:
	arm-linux-gnueabi-gcc -c -o led.o led.c
	arm-linux-gnueabi-gcc -c -o uart.o uart.c
	arm-linux-gnueabi-gcc -c -o init.o init.c
	arm-linux-gnueabi-gcc -c -o main.o main.c
	arm-linux-gnueabi-gcc -c -o start.o start.S
	#arm-linux-gnueabi-ld -Ttext 0 -Tdata 0x30000000  start.o led.o uart.o init.o main.o -o sdram.elf
	arm-linux-gnueabi-ld -T sdram.lds start.o led.o uart.o init.o main.o -o sdram.elf
	arm-linux-gnueabi-objcopy -O binary -S sdram.elf sdram.bin
	arm-linux-gnueabi-objdump -D sdram.elf > sdram.dis
clean:
	rm *.bin *.o *.elf *.dis
	
