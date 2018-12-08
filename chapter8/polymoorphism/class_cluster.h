#include <iostream>

using namespace std;

class Base
{
public:
	virtual void print();
	virtual ~Base();
};

class Foo: public Base 
{
public:
	void print();
	~Foo();
};

class Derived: public Base 
{
public:
	void print();
	~Derived();
};
