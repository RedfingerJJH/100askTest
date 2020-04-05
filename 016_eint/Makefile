all: start.o led.o uart.o init.o main.o exception.o interrupt.o
	arm-linux-gnueabi-ld -T sdram.lds $^ -o sdram.elf
	arm-linux-gnueabi-objcopy -O binary -S sdram.elf sdram.bin
	arm-linux-gnueabi-objdump -D sdram.elf > sdram.dis
clean:
	rm *.bin *.o *.elf *.dis

uart.o : uart.c
	arm-linux-gnueabi-gcc -c -fno-stack-protector -o $@ $<

%.o : %.c
	arm-linux-gnueabi-gcc -c -o $@ $<

%.o : %.S
	arm-linux-gnueabi-gcc -c -o $@ $<
