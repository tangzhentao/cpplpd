#include "class.h"
#include <iostream>

using namespace std;

void Foo::print ()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
void Foo::show()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
void Foo::show1()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
void Foo::show2()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
void Foo::show3()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
void Foo::show4()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
void Foo::show5()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
void Foo::show6()
{
	cout << typeid(*this).name() << "::" << __func__  << endl;
}
