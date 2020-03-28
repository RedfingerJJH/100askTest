#include <stdio.h>

struct person{
	char *name;
	int age;
	char score;
	int id;
};

/* 
 *int printf(const char *format, ...); 
 *依据:x86平台,函数调用时参数传递是使用堆栈来实现的 
 *目的:将所有传入的参数全部打印出来 
 */
 int push_test(const char *format,...)
 {
 	char *p = (char *)&format;
	int i;
	struct person per;
	char c;
	double d;

	printf("arg1: %s\n",format);

	//---------------------
	p = p + sizeof(char *);

	/*指针对连续空间操作时: 1) 取值  2)移动指针*/ 
	i = *((int *)p);
	p = p + sizeof(int);
	printf("arg2: %d\n",i);

	//---------------------
	/*指针对连续空间操作时: 1) 取值  2)移动指针*/ 
	per = *((struct person*)p);
	p = p + sizeof(struct person);
	printf("arg3: .name = %s, .age = %d, .score = %c, .id = %d\n",\
		          per.name,   per.age,   per.score,   per.id);

	//---------------------
	/*指针对连续空间操作时: 1) 取值  2)移动指针*/ 
	c = *((char *)p);
	p = p + ((sizeof(char) + 3) & ~3);
	printf("arg4: %c\n",c);

	//---------------------
	/*指针对连续空间操作时: 1) 取值  2)移动指针*/ 
	d = *((double *)p);
	p = p + sizeof(double);
	
	printf("arg5: %f\n",d);

	return 0;
 }

int main(int argc, char *argv[])
{
	struct person per ={"www.100ask.arg",10,'A',123};

	printf("sizeof(char)   =%d\n",sizeof(char));
	printf("sizeof(int)    =%d\n",sizeof(int));
	printf("sizeof(char *) =%d\n",sizeof(char *));
	printf("sizeof(char **)=%d\n",sizeof(char **));
	printf("sizeof(struct person) =%d\n",sizeof(struct person));
	
	//push_test("abc");
	//push_test("abc",123);
	//push_test("abc",123,per);
	//push_test("abc",123,per,'c');
	push_test("abc",123,per,'c',2.79);
	
	return 0;
}

