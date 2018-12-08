#include <iostream>

/*
 * 复数：z = a + bi;
 */
class Complex
{
public:
	Complex(double a, double b);

	/*
	Complex operator + (const Complex &c) const;
	Complex operator - (const Complex &c) const;
	*/

	void print() const;

	friend Complex operator + (const Complex &left, const Complex &right);
	friend Complex operator - (const Complex &left, const Complex &right);
	friend std::ostream & operator << (std::ostream &output, const Complex &c);
private:
	double _a;
	double _b;

};
