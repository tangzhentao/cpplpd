/*
 * 测试对象数组元素初始化的情况
 * 1、看看如果只是定义一个数组而不初始化，会不会调用默认的构造函数进行初始化
 *
 * 结论：
 * 定义一个对象数组时，无论是否初始化，都会调用构造函数去初始化。
 * 基本类型的数组，在给出的初始化数量小于数组大小时，其余的数组元素会被初始化为0
 * 在对象数组中，未给出初始化值得元素的值是随机的
 */
#include <iostream>

using namespace std;
class Point
{
public:
	Point()
	{
		cout << "default contructor: "<< x << ", " << y << endl;
	}
	Point(int i, int j): x(i), y(j)
	{
		cout << "custom contructor: "<< x << ", " << y << endl;
	}

private:
	int x, y;
};

void func ()
{
	cout << "在普通函数中定义一个对象数组" << endl;
	Point p1[3];
	cout << "在普通函数中定义一个对象数组并初始化" << endl;
	Point p2[3] = {Point(1, 1)};
}
int main()
{
	cout << "在main函数中定义一个对象数组" << endl;
	Point p1[3];
	cout << "在main函数中定义一个对象数组并初始化" << endl;
	Point p2[10] = {Point(1, 1)};

	func();
	return 0;
}
