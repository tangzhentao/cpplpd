/*
 * 测试C语言中，函数参数为空时，代表什么意思？
 * 是代表0个参数，还是任何参数
 *
 * 结论：
 * C言语中，函数参数为空时()，表示可以传递任意个数，任意类型的参数，只是函数中无法访问这些参数。
 * 在调用是给函数传递参数，编译时会报警告但不报错。
 * 如果函数参数为(void), 则明确表示不能传递参数，如果传了，编译时会报错。
 */
#include <stdio.h> 

void print()
{
	printf("print\n");
}

void show(void)
{
	printf("show\n");
}

int main()
{
	print();
	print(1);
	print(1, "abc", 2.5);

	printf("\n");

	show();
	show(2);
	return 0;
}
