#include "uart.h"

/* start.S调用 */
void printException(unsigned int cpsr, char *str)
{
	puts("Exception! cpsr = ");
	printHex(cpsr);
	puts(" ");
	puts(str);
	puts("\n\r");
}
