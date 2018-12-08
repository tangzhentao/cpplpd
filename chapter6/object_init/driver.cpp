/*
 * 测试整型默认转化为类
 */

#include <iostream>

using namespace std;

class foo
{
public:
	foo(int i): data(i)
	{
		cout << typeid (this).name() << ", "<< __func__ << endl;
	}

	void print()
	{
		cout << "data: " << data << endl;
	}

private:
	int data;
};

void print(foo f)
{
	f.print();
}

int main()
{
	cout << "使用整型初始化foo类对象" << endl;
	foo f = 5;
	f.print();

	f = 10;
	f.print();

	print(100);

	return 0;
}
