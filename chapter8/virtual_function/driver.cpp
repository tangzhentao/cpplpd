/*
 * 测试派生类中不实现虚函数时，
 * 会不会继承父类的实现；
 */
#include "class.h"

using namespace std;

int main()
{
	Base b;
	b.print();

	Derived d;
	d.print();
	return 0;
}
