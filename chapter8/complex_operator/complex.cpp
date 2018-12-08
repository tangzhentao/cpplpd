
#include "complex.h"
#include <cxxabi.h>

using namespace std;

Complex::Complex(double a, double b): _a(a), _b(b)
{
	//char* name = abi::__cxa_demangle(typeid(this).name(), nullptr, nullptr, nullptr); 
	const char *name = typeid(*this).name();
	cout << name << ':' << __func__ << endl;
}

/*
Complex Complex::operator + (const Complex &c) const
{
	cout << "member function" << endl;
	double a = _a + c._a;
	double b = _b + c._b;

	return Complex(a, b);
}

Complex Complex::operator - (const Complex &c) const
{
	cout << "member function" << endl;
	double a = _a - c._a;
	double b = _b - c._b;

	return Complex(a, b);
}
*/

void Complex::print() const
{
	cout <<'(' << _a << " + " << _b << "i" << ')'  << endl;
}
