/*
 * 练习静态成员变量的声明、定义、使用
 */
#include <iostream>
#include "static_member.h"

using namespace std;


void doSomething(A a)
{
	cout << "do something begin" << endl;
	A a1;
	A::printCount();
	cout << "do something end" << endl;
}

int A::count = 0;

int main()
{
	A::printCount();
	A a1;
	A::printCount();

	doSomething(a1);
	A::printCount();

	A a2;
	A::printCount();
	return 0;
}
