all: start.o led.o uart.o init.o main.o exception.o interrupt.o timer.o \
nor_flash.o my_printf.o string_utils.o
	arm-linux-gnueabi-ld -T sdram.lds $^ -o sdram.elf
	arm-linux-gnueabi-objcopy -O binary -S sdram.elf sdram.bin
	arm-linux-gnueabi-objdump -D sdram.elf > sdram.dis
clean:
	rm *.bin *.o *.elf *.dis

%.o : %.c
	arm-linux-gnueabi-gcc -march=armv4 -nostdlib -c -o $@ $<

%.o : %.S
	arm-linux-gnueabi-gcc -march=armv4 -c -o $@ $<
