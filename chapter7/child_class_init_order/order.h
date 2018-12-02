/*
 * 1、测试初始化派生类对象时，初始化基类和成员对象的顺序
 * 2、测试销毁派生类对象时，自己析构函数、成员对象的析构函数和基类的析构函数的调用顺序
 */
#include <iostream>

using namespace std;

class BaseA
{
public:
	BaseA()
	{
		cout << "default - " << __func__ << ": " << data << endl;
	}
	~BaseA()
	{
		cout <<  __func__ << endl;
	}

	BaseA(int x): data(x)
	{
		cout << "custom - " << __func__ << ": " << data << endl;
	}

private:
	int data;
};

class BaseB
{
public:
	BaseB()
	{
		cout << "default - " << __func__ << ": " << data << endl;
	}
	~BaseB()
	{
		cout << __func__ << endl;
	}

	BaseB(int x): data(x)
	{
		cout << "custom - " << __func__ << ": " << data << endl;
	}

private:
	int data;
};

class MemberA
{
public:
	MemberA()
	{
		cout << "default - " << __func__ << ": " << data << endl;
	}
	~MemberA()
	{
		cout << __func__ << endl;
	}

	MemberA(int x): data(x)
	{
		cout << "custom - " << __func__ << ": " << data << endl;
	}

private:
	int data;
};

class MemberB
{
public:
	MemberB()
	{
		cout << "default - " << __func__ << ": " << data << endl;
	}
	~MemberB()
	{
		cout << __func__ << endl;
	}

	MemberB(int x): data(x)
	{
		cout << "custom - " << __func__ << ": " << data << endl;
	}

private:
	int data;
};

class Derived: public BaseB, public BaseA
{
public:
	Derived()
	{
		cout << "default - " << __func__ << endl;
	}
	~Derived()
	{
		cout << __func__ << endl;
	}
	Derived(int a, int da, int db):
		BaseA(a), dataA(da), dataB(db)
	{
		cout << "coustom apart - " << __func__ << endl;
	}
	Derived(int a, int b, int da, int db):
		BaseA(a), BaseB(b), dataA(da), dataB(db)
	{
		cout << "coustom all - " << __func__ << endl;
	}

private:
	MemberB dataB;
	MemberA dataA;
	
};
