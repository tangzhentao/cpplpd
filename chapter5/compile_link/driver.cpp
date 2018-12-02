/*
 * 制造编译期间的类型重定义错误和链接期间的
 */
#include <iostream>
#include "b.h"

using namespace std;


extern int a;
extern int a;

int main()
{
	cout << "hello" << endl;
	cout << a << endl;
	return 0;
}
