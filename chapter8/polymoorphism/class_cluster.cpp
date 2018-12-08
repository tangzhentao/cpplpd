
#include "class_cluster.h"

void Base::print()
{
	cout << typeid(*this).name() << "::" << __func__ << endl;	
}
void Foo::print()
{
	cout << typeid(*this).name() << "::" << __func__ << endl;	
}
void Derived::print()
{
	cout << typeid(*this).name() << "::" << __func__ << endl;	
}

Base::~Base()
{
	cout << typeid(*this).name() << "::" << __func__ << endl;	
}
Foo::~Foo()
{
	cout << typeid(*this).name() << "::" << __func__ << endl;	
}
Derived::~Derived()
{
	cout << typeid(*this).name() << "::" << __func__ << endl;	
}
