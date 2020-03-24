/*
Makefile的核心---规则 :

目标: 依赖1 依赖2 ...
[TAB]命令

当"目标文件"不存在, 
或某个依赖文件比目标文件"新",
则: 执行"命令"

002_Makefile的语法
a. 通配符: %.o
   $@ 表示目标
   $< 表示第1个依赖文件
   $^ 表示所有依赖文件
*/

#include <stdio.h>

int main(void)
{
	func_b();
	func_c();
	return 0;
}