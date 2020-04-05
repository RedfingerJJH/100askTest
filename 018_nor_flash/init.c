#include "s3c2440_soc.h"

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

#if 0
/**************************************************************************   
* 设置控制SDRAM的13个寄存器
* 使用位置无关代码
**************************************************************************/   
void memsetup(void)
{
	const static unsigned long *p = (unsigned long *)MEM_CTL_BASE;	
	p[0] = 0x22111110;		//BWSCON
	p[1] = 0x00000700;		//BANKCON0
	p[2] = 0x00000700;		//BANKCON1
	p[3] = 0x00000700;		//BANKCON2
	p[4] = 0x00000700;		//BANKCON3	
	p[5] = 0x00000700;		//BANKCON4
	p[6] = 0x00000700;		//BANKCON5
	p[7] = 0x00018005;		//BANKCON6
	p[8] = 0x00018005;		//BANKCON7
	p[9] = 0x008e07a3;		//REFRESH,HCLK=12MHz:0x008e07a3,HCLK=100MHz:0x008e04f4
	p[10] = 0x000000b2;		//BANKSIZE
	p[11] = 0x00000030;		//MRSRB6
	p[12] = 0x00000030;		//MRSRB7
}

void sdram_init2(void)
{
	unsigned int arr[] = {
		0x22000000, 	//BWSCON
		0x00000700, 	//BANKCON0
		0x00000700, 	//BANKCON1
		0x00000700, 	//BANKCON2
		0x00000700, 	//BANKCON3
		0x00000700, 	//BANKCON4
		0x00000700, 	//BANKCON5
		0x00018001, 	//BANKCON6
		0x00018001, 	//BANKCON7
		0x008404f5, 	//REFRESH,HCLK=12MHz:0x008e07a3,HCLK=100MHz:0x008e04f4
		0x000000b1,		//BANKSIZE
		0x00000020,		//MRSRB6
		0x00000020,		//MRSRB7
		};
	volatile unsigned int * p = (volatile unsigned int *)0x48000000;
	int i;

	for (i = 0; i < 13; i++)
	{
		*p = arr[i];
		p++;
	}
}
#endif

/* start.S调用 */
void copy2sdram(void)
{
	/* 要从lds文件中获得 __code_start, __bss_start
	 * 然后从0地址把数据复制到__code_start
	 */
	extern int __code_start, __bss_start;

	volatile unsigned int *dest = (volatile unsigned int *)&__code_start;
	volatile unsigned int *end  = (volatile unsigned int *)&__bss_start;
	volatile unsigned int *src  = (volatile unsigned int *)0;

	while (dest < end)
	{
		*dest++ = *src++;
	}
}

/* start.S调用 */
void clean_bss(void)
{
	/* 要从lds文件中获得 __bss_start, _end
	 */
	extern int _end, __bss_start;

	volatile unsigned int *start = (volatile unsigned int *)&__bss_start;
	volatile unsigned int *end   = (volatile unsigned int *)&_end;

	while (start <= end)
	{
		*start++ = 0;
	}
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
		if (p[i] != 'A')
			return -1;
	}
	
	return 0;
}
