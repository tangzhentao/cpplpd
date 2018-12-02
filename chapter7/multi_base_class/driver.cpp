/*
 * 测试派生类有多个父类时，且存在同名函数成员和数据成员时的访问情况；
 */
#include <iostream>

using namespace std;

class Base1 {
public:
    int data;
    void print() {
    cout << "Base1 print: data = "<< data  << endl;
    }
};

class Base2 {
public:
    int data;
    void print() {
    cout << "Base2 print: data = " << data << endl;
    }
};

class Derived: public Base1, public Base2 {
public:
    int data;
    void print() {
    cout << "Derived print: data = " << data << endl;
    }
};

int main() {
    Derived d;
    Derived *p = &d;

    d.data = 1;
    d.print();

    d.Base1::data = 2;
    d.Base1::print(); // 打印的data是Base1的data

    p->Base2::data = 3; 
    p->Base2::print(); // 打印的data是Base2的data

	cout << "Base1对象占几个字节：" << sizeof(Base1) << endl; // 4
	cout << "Base2对象占几个字节：" << sizeof(Base2) << endl; // 4
	cout << "Derived对象占几个字节：" << sizeof(Derived) << endl; // 12,就是说Derived对象内存中有Base1和Base2的完整内存
}
