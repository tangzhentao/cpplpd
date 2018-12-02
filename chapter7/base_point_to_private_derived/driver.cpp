/*
 * 测试基类指针能不能指向私有继承的派生类对象
 *
 * 结论：
 * 不能
 */
#include <iostream>

using namespace std;

class Base
{
	public:
		int data;
};

class Derived: private Base
{
};

int main()
{
	cout << "hello" << endl;
	Base *p = new Derived; // 会报错
	return 0;
}
