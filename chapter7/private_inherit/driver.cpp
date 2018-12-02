/*
 * 测试私有、保护继承的类是否遵守类兼容性规则
 *
 * 结论：
 * 不遵守
 */
#include <iostream>

using namespace std;

class Base
{
	public:
		void print ()
		{
			cout << "data1: " << data1 << ", data2: " << data2 << endl;
		}

		int data1;
	private:
		int data2;
};

class Derived: public Base
{

};

void show(Base b)
{
	cout << "show" << endl;
}
int main()
{
	cout << "hello" << endl;

	Base b;
	Derived d;
	show(b);
	show(d); // 会报错，当继承方式为private和protected的时候
	return 0;
}
