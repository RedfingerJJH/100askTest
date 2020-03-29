#include "s3c2440_soc.h"
#include "led.h"
#include "uart.h"
#include "init.h"

char g_Char = 'A';
const char g_Char2 = 'B';
int g_A = 0;
int g_B;

int main(void)
{
	uart0_init();
	//puts("Hello, world\n");
	
	while(1)
	{
		putchar(g_Char);
		g_Char++;		/* nor启动时，此代码无效 */
		delay(100000);
	}

	return 0;
}
