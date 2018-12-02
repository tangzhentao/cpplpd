#include "static_member.h"
A::A()
{
	cout << "create" << endl;
	++count;
}

A::A(A &a)
{
	data = a.data;
	cout << "copy" << endl;
	++count;
}

A::~A()
{
	cout << "remove" << endl;
	--count;
}

void A::printCount()
{
	cout << "count: " << count << endl;
}

// int A::count = 0;
