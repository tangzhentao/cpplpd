#include <iostream>

class Wife;
class Husband
{
public:
	Husband(int a, int m): age(a), money(m)
	{

	}

	void print()
	{
		printf("age: %d, money: %d\n", age, money);
	}

	friend void banckPrint(Husband &h);

public:
	int age;
	//friend class Wife;

private:
	int money;
};
