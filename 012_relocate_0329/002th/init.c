#include "s3c2440_soc.h"
//#include "uart.h"

void sdram_init(void)
{
	BWSCON = 0x22000000;
	
	BANKCON6 = 0x18001;
	BANKCON7 = 0x18001;
	
	REFRESH = 0x8404F5;
	
	BANKSIZE = 0xB1;
	
	MRSRB6 = 0x20;
	MRSRB7 = 0x20;
}

int sdram_test(void)
{
	volatile unsigned char *p = (volatile unsigned char *)0x30000000;
	int i;
	
	//wriite sdram
	for (i = 0; i < 10; i++)
		p[i] = 'A';
	
	//read sdram
	for (i = 0; i < 10; i++)
	{
		//putchar(p[i]);
		if (p[i] != 'A')
			return -1;
	}
		
	return 0;
}
