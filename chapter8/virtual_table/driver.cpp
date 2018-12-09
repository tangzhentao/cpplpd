/*
 * 通过查看类占内存的大小，推测虚函数表指针vptr的存在，
 * 进而推测虚函数表的存在
 */
#include <iostream>
#include "class.h"

using namespace std;

int main()
{
	cout << "Foo size: " << sizeof(Foo) << endl;
	cout << "hello" << endl;
	return 0;
}
