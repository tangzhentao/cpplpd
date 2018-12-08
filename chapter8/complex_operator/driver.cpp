#include "complex.h"

/*
 * 练习成员函数方式的操作符重载和
 * 普通函数方式的操作符重载
 * 
 * 当两种形式的操作符重载都出现时,
 * 编译时会报ambiguous错误，有歧义；
 */


using namespace std;

Complex operator + (const Complex &left, const Complex &right)
{
	cout << "no member function" << endl;
	double a = left._a + right._a;
	double b = left._b + right._b;

	return Complex(a, b);
}

Complex operator - (const Complex &left, const Complex &right)
{
	cout << "no member function" << endl;
	double a = left._a - right._a;
	double b = left._b - right._b;

	return Complex(a, b);
}

ostream & operator << (ostream &output, const Complex &c)
{
	output <<'(' << c._a << " + " << c._b << "i" << ')';
	return output;
}

int main ()
{
	Complex c1(2, 4);
	Complex c2(4, 2);

	Complex c = c1 + c2;
	Complex c3 = c1 - c2;
	
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c << endl;

	return 0;
}
