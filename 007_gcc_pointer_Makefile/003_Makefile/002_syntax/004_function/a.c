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

b. 假想目标：.PHONY

c. 即时变量、延时变量、export
简单变量（即时变量）
A := xxx #A的值即刻确定，在定义时即确定
B = xxx  #B的值使用到时才确定

:=  #即时变量
=   #延时变量
?=  #延时变量，如果是第1次定义才起效，如果在前面该变量已定义则忽略这句
+=  #附加，它是即时变量还是延时变量取决于前面的定义

003_Makefile函数
a. $(foreach var, list, text)
b. $(filter pattern..., text)      # 在text中取出符合patten格式的值
   $(filter-out pattern..., text)  # 在text中取出不符合patten格式的值

c. $(wildcard pattern)             # pattern定义了文件名的格式,
                                   # wildcard取出其中存在的文件
d. $(patsubst pattern, replacement, text)  # 从列表中取出每一个值
                                           # 如果符合pattern
										   # 则替换为replacement
*/

#include <stdio.h>

int main(void)
{
	func_b();
	func_c();
	return 0;
}