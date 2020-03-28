/* 
 * 64位机器：gcc -m32 -o printf_test printf_test.c
 * 32位机器：gcc -o printf_test printf_test.c
 */

 #include <stdio.h>

 void printf_test(void)
 {
 	printf("hello world\n");
	printf("This is www.100ask.org my_printf test\n");
	printf("test char           =%c,%c\n", 'A','a');
	printf("test decimal number =%d\n",    123456);
	printf("test decimal number =%d\n",    -123456);
	printf("test hex     number =0x%x\n",  0x55aa55aa);
	printf("test string         =%s\n",    "www.100ask.arg");
 }

 int main(int argc, char *argv[])
 {
 	printf_test();
	return 0;
 }
