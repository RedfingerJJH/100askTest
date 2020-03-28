all:
	arm-linux-gnueabi-gcc -c -o led.o led.c
	arm-linux-gnueabi-gcc -c -o uart.o uart.c
	arm-linux-gnueabi-gcc -c -fno-stack-protector -o my_printf.o my_printf.c
	arm-linux-gnueabi-gcc -c -o main.o main.c
	arm-linux-gnueabi-gcc -c -o start.o start.S
	arm-linux-gnueabi-ld  -Ttext 0 -Tdata 0xe80 -o uart.elf start.o led.o uart.o my_printf.o main.o
	arm-linux-gnueabi-objcopy -O binary -S uart.elf uart.bin
	arm-linux-gnueabi-objdump -D uart.elf > uart.dis
clean:
	rm *.bin *.o *.elf *.dis
	
