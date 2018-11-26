/*
 * 测试仅靠const实现函数重载的调用原则
 *
 * 书中描述：
 * 如果两个函数的声明仅仅是有无const的区别，也是函数重载。
 * 对常对象调用函数时会调用重载的常函数版本，
 * 对非常对象调用函数时，则调用声明靠前的函数。
 *
 * 结论：
 * 书上描述的不对
 * 对常对象调用函数调用的是常函数，但
 * 对非常对象调用函数调用的是普通函数不是常函数
 * 且和函数定义的顺序无关。
 * 环境是Mac OS 10.14
 *
 */
#include <iostream>

using namespace std;

class foo
{
	public:
		foo (int d);
		void print() const;
		void print ();

	private:
		int data;
};

foo::foo(int d): data(d)
{
}

void foo::print() const
{
	printf("const %s: %d\n", __func__, data);
}


void foo::print() 
{
	printf("%s: %d\n", __func__, data);
}

int main()
{
	cout << "hello" << endl;

	const foo f1(3);
	f1.print();
	f1.print();

	foo f2(4);
	f2.print();
	f2.print();
	return 0;
}
