/*
 * 测试友元类和友元函数
 */
#include <iostream>
#include "wife.h"
#include "husband.h"
#include "exhusband.h"

using namespace std;

void banckPrint(Husband &h)
{
	cout << "customer age: " << h.age
		<< ", money: " << h.money << endl;
}
int main()
{
	Husband h(30, 1000);
	Wife w(26, 600);

	h.print();
	w.print();
	w.printHusband(h);

	banckPrint(h);

	cout << "我信任你，我儿子是否信任你" << endl;

	Exhusband eh(32, 300);
	eh.print();
	w.printHusband(eh);
	cout << "hello" << endl;
	w.printExhusband(eh);
	return 0;
}
