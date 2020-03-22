/*
在64位的ubuntu系统，使用gcc想编译出32位的应用程序，需要使用gcc  -m32选项，
但是使用gcc -m32选项后，出现：fatal error: sys/cdefs.h: No such file or directory

可以使用如下方法解决：
sudo apt-get update
sudo apt-get purge libc6-dev
sudo apt-get install libc6-dev
sudo apt-get install libc6-dev-i386
*/

#include <stdio.h>

void test0(void)
{
	char c;
	char *pc;
	
	/* 第一步：所有变量都保存在内存中，我们打印一下变量的存储地址 */
	printf("&c = %p\n",&c);
	printf("&pc= %p\n",&pc);
	
	/* 第二步：所有变量都可以保存某些值，接着赋值并打印 */
	c = 'A';
	pc= &c;
	printf("c = %c\n",c);
	printf("pc= %p\n",pc);
	
	/* 第三步：使用指针：1）取值，2）移动指针 */
	printf("*pc = %c\n",*pc);
	printf("//--------------------\n");
}

void test1(void)
{
	int ia;
	int *pi;
	char *pc;
	
	/* 第一步：所有变量都保存在内存中，我们打印一下变量的存储地址 */
	printf("&ia = %p\n",&ia);
	printf("&pi = %p\n",&pi);
	printf("&pc = %p\n",&pc);
	
	/* 第二步：所有变量都可以保存某些值，接着赋值并打印 */
	ia = 0x12345678;
	pi = &ia;
	pc = (char *)&ia;
	printf("ia = 0x%x\n",ia);
	printf("pi = %p\n",pi);
	printf("pc = %p\n",pc);
	
	/* 第三步：使用指针：1）取值，2）移动指针 */
	printf("*pi = 0x%x\n",*pi);
	printf("pc  = %p\n",pc);  printf("*pc = 0x%x\n",*pc);  pc = pc + 1;
	printf("pc  = %p\n",pc);  printf("*pc = 0x%x\n",*pc);  pc = pc + 1;
	printf("pc  = %p\n",pc);  printf("*pc = 0x%x\n",*pc);  pc = pc + 1;
	printf("pc  = %p\n",pc);  printf("*pc = 0x%x\n",*pc);
	printf("//--------------------\n");
}

int main(void)
{
	printf("sizeof(char)    = %d\n",sizeof(char));
	printf("sizeof(int)     = %d\n",sizeof(int));
	printf("sizeof(char *)  = %d\n",sizeof(char *));
	printf("sizeof(char **) = %d\n",sizeof(char **));
	printf("//--------------------\n");
	test0();
	test1();
	return 0;	
}