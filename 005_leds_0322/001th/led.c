void delay(volatile int d)
{
	while(d--);
}

int main(void)
{
	volatile unsigned int *pGPFCON = (volatile unsigned int *)0x56000050;
	volatile unsigned int *pGPFDAT = (volatile unsigned int *)0x56000054;
	int idx = 0;
	
	/* 设置GPFCON让GPF4/5/6配置为输出引脚 */
	*pGPFCON &= ~((3<<8)|(3<<10)|(3<<12));
	*pGPFCON |= ((1<<8)|(1<<10)|(1<<12));
	
	while(1)
	{
		*pGPFDAT |= (7<<4);
		*pGPFDAT &= ~(1<<(idx+4));
		delay(100000);
		idx++;
		if (idx == 3)
			idx = 0;
	}
	
	return 0;
}