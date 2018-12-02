#include <iostream>

class Husband;
class Exhusband;
class Wife
{
public:
	Wife(int a, int m): age(a), money(m)
	{
	}

	void print()
	{
		printf("age: %d, money: %d\n", age, money);
	}

	void printHusband(Husband &h);
	void printExhusband(Exhusband &eh);

private:
	int age;
	int money;

};
