/*
 * 测试把多继承的派生类指针赋值给基类时，指针所指的地址可能会反生偏移。
 * 之所以会偏移是为了找到派生类对象内存中指定基类的成员所在的内存区域。
 */
#include <iostream>

using namespace std;

class A
{
public:
	int data;
};
class B
{
public:
	int data;
};
class C: public A, public B
{
public:
	int data;
};
int main()
{
	cout << "hello" << endl;
	C *pc = new C;
	A *pa = pc;
	B *pb = pc; // 赋值之后pb的值和pc的值是不一样的

	cout << "pc: " << pc << '\n' << "pa: " << pa << '\n' << "pb: " << pb << '\n';
	return 0;
}
