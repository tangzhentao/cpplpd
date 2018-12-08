/*
 * 体验多态
 */
#include "class_cluster.h"

using namespace std;

void print(Base *b)
{
	b->print();
}

void print(Base b)
{
	b.print();
}

void dismiss(Base *b)
{
	cout << endl;
	cout << "dismis start." << endl;
	delete b;
	cout << "dismis end." << endl;
	cout << endl;
}

int main()
{
	Base b;
	Foo f;
	Derived d;

	print(&b);
	print(&f);
	print(&d);

	/*
	print(b);
	print(f);
	print(d);
	*/
	Base *pb = new Base;
	Base *pf = new Foo;
	dismiss(pb);
	dismiss(pf);

	return 0;
}
