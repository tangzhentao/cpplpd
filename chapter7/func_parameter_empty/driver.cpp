/*
 * 测试C++中函数参数列表为空时是什么意思？
 * 是void还是任意参数类型。
 *
 * 结论：
 * 表示没有参数
 */
#include <iostream>

using namespace std;

void print (void)
{
	cout << "print" << endl;
}

int main()
{
	cout << "hello" << endl;
	print();
//	print(2); // 报错：需要0个参数，但是传递了1个参数

	return 0;
}
