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
	/* 设置TIMER0的时钟 */
	/* Timer clk = PCLK / {prescaler value+1} / {divider value} 
	             = 50000000/(99+1)/16
	             = 31250
	 */
	TCFG0 = 99;  /* Prescaler 0 = 99, 用于timer0,1 */
	TCFG1 &= ~0xf;
	TCFG1 |= 3;  /* MUX0 : 1/16 */

	/* 设置TIMER0的初值 */
	TCNTB0 = 15625;  /* 0.5s中断一次 */

	/* 加载初值, 启动timer0 */
	TCON |= (1<<1);   /* Update from TCNTB0 & TCMPB0 */

	/* 设置为自动加载并启动 */
	TCON &= ~(1<<1);
	TCON |= (1<<0) | (1<<3);  /* bit0: start, bit3: auto reload */

	/* 设置中断 */
#if 0
	register_irq(10, timer_irq);
#else
	INTMSK &= ~(1<<10);  /* enable timer0 int */
#endif
}
