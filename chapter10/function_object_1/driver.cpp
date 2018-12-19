/*
 * 例10-13
 * 使用普通函数作为函数对象
 *
 * 例10-14
 * 使用重载了调用操作符的对象作为函数对象
 *
 * 例10-14
 * 使用STL标准对象
 */
#include <iostream>
#include <numeric>

using namespace std;

int mult(int x, int y)
{
	return x * y;
}

class Multiply
{
public:
	int operator () (int x, int y)
	{
		return x * y;
	}
};

int main()
{
	int a[] = {2, 5, 3, 6, 8};
	const int N = sizeof(a) / sizeof(int);

	// 使用默认的加法运算
	int sum = accumulate(a, a+N, 0);
	// 使用函数传递自定义的运算规则——乘法
	int product = accumulate(a, a+N, 1, mult);

	cout << "sum: " << sum << endl;
	cout << "product: " << product << endl;
	// 使用对象传递自定义的运算规则——乘法
	product = accumulate(a, a+N, 1, Multiply() );
	cout << "product: " << product << endl;
	
	// 使用STL标准函数对象传递自定义的运算规则——乘法
	product = accumulate(a, a+N, 1, multiplies<int>() );
	cout << "product: " << product << endl;

	return 0;
}
