#include "s3c2440_soc.h"

void timer_irq(int irq)
{
	static int idx = 0;
	
	GPFDAT |= (7<<4);
	GPFDAT &= ~(1<<(idx+4));
	idx++;
	if (idx == 3)
		idx = 0;
}

void timer_init(void)
{
	/* ����TIMER0��ʱ�� */
	/* Timer clk = PCLK / {prescaler value+1} / {divider value} 
	             = 50000000/(99+1)/16
	             = 31250
	 */
	TCFG0 = 99;  /* Prescaler 0 = 99, ����timer0,1 */
	TCFG1 &= ~0xf;
	TCFG1 |= 3;  /* MUX0 : 1/16 */

	/* ����TIMER0�ĳ�ֵ */
	TCNTB0 = 15625;  /* 0.5s�ж�һ�� */

	/* ���س�ֵ, ����timer0 */
	TCON |= (1<<1);   /* Update from TCNTB0 & TCMPB0 */

	/* ����Ϊ�Զ����ز����� */
	TCON &= ~(1<<1);
	TCON |= (1<<0) | (1<<3);  /* bit0: start, bit3: auto reload */

	/* �����ж� */
#if 0
	register_irq(10, timer_irq);
#else
	INTMSK &= ~(1<<10);  /* enable timer0 int */
#endif
}
