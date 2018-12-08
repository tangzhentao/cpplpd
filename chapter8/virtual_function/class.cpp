#include "class.h"

using namespace std;

void Base::print()
{
	printf("hello, test\n");
	cout << typeid(*this).name() << "::" << __func__ << endl;
}
