/*
 * 测试能不能手动调用构造函数
 *
 * 结论：
 * 不能手动调用
 */
#include <iostream>

using namespace std;

class A
{
	public:
		A(): data(0)
		{
		}

		int data;
};

int main()
{
	cout << "hello" << endl;
	A a;
	a.data = 2;

	A *p = &a;
	cout << "a.data: " << a.data << endl;
	// a.A(); // 会报错
	cout << "a.data: " << a.data << endl;

	return 0;
}
