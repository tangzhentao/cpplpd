/*
 * 测试一个类作为全局变量和作为局部变量时，默认的初始化值 是否一样
 *
 * 结论：
 * 全局的类变量的基本类型的成员变量和全局的基本类型的变量会被默认初始化为0;
 * 静态的变量也会被初始化为0；
 * 概况来说就是有静态生命周期的变量会被初始化为0；
 * 在main函数中也是这种情况(有点不理解，因为main中的变量时局部变量不应默认初始化为0的)
 *
 * 函数中的局部变量没有默认初始化为0；
 */
#include <iostream>

class Person
{
public:
	int age;
	int ID;

	void print ()
	{
		printf("age: %d, ID: %d\n", age, ID);
	}
};

using namespace std;

Person p1;
int i;

void aMethod ()
{
	cout << "method begin." << endl;
	Person p;
	static Person p1;
	p.print();
	p1.print();

	int i;
	cout << "i: " << i << endl;
	cout << "method end." << endl;
}

int main()
{
	int j;
	Person p2;
	p1.print();
	p2.print();
	cout << "i: " << i << ", j: " << j << endl;

	aMethod();
	return 0;
}
