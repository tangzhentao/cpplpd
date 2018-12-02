#include <iostream>

class Exhusband;
class Husband;
class Exhusband: public Husband
{
public:
	Exhusband(int a, int m): Husband(a, m)
	{
	}

	int years;
private:
	int password;

	friend class Wife;	
};
