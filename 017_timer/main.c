#include "s3c2440_soc.h"
#include "led.h"
#include "uart.h"
#include "init.h"
#include "interrupt.h"
#include "timer.h"

volatile char g_Char = 'A';
volatile char g_Char3 = 'a';
const char g_Char2 = 'B';
int g_A = 0;
int g_B;

int main(void)
{
	int i = 0;

	led_init();
	//interrupt_init();  /* ��ʼ���жϿ����� */
	key_eint_init();   /* ��ʼ������, ��Ϊ�ж�Դ */
	timer_init();
	
	puts("\n\rg_A = ");
	printHex(g_A);
	puts("\n\r");
	
	while(1)
	{
#if 0		
		puts("\n\rg_Char = ");
		printHex(g_Char);
		puts("\n\r");

		puts("\n\rg_Char3 = ");
		printHex(g_Char3);
		puts("\n\r");
#endif

		putchar(g_Char);
		g_Char++;
		
		putchar(g_Char3);
		g_Char3++;

		i++;
		if (i == 26)
		{
			i = 0;
			g_Char = 'A';
			g_Char3 = 'a';
			puts("\n\r");
		}
		
		delay(100000);
	}

	return 0;
}

