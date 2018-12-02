/*
 * 测试常量指针和指针常量
 */
#include <iostream>

using namespace std;

int main()
{
	cout << "hello" << endl;

	int i = 10;
	int *p0 = &i;
	const int *p1 = &i;
	int * const p2 = p1;

	p1 = p2;

	return 0;
}
