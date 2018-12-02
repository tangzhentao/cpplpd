/*
 *
 */
#include <iostream>
#include "order.h"

using namespace std;

int main()
{
	cout << "hello" << endl;
	Derived d1;
	cout << "---------------" << endl;
	Derived d2(1, 3, 4);
	cout << "---------------" << endl;
	Derived d3(1, 2, 3, 4);
	return 0;
}
