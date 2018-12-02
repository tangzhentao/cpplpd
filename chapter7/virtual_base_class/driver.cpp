/*
 * 测试使用虚继承时，第一代类，对继承两个第二代类的第三代类的影响
 */
#include <iostream>

using namespace std;

class Base0 {
public:
    int data;
    int data1;
    int data2;
    int data3;
    int data4;
    int data5;
    void print() {
    cout << "Base0 print: data = "<< data  << endl;
    }
};
class Base1: virtual public Base0 {
};

class Base2: virtual public Base0 {
};

class Derived: public Base1, public Base2 {
};

int main() {
    Derived d;
    Derived *p = &d;

	// 其实下面两行操作的是同一个data
    d.Base1::data = 2;
    p->Base2::data = 3; 

    d.Base1::print(); // 打印结果是3
    p->Base2::print(); // 打印结果是3 

	cout << "Base0对象占几个字节：" << sizeof(Base0) << endl; // 24
	cout << "Base1对象占几个字节：" << sizeof(Base1) << endl; // 32 多了一个指针数据，指向Base0的数据开始的地址
	cout << "Base2对象占几个字节：" << sizeof(Base2) << endl; // 32 多了一个指针数据，指向Base0的数据开始的地址 
	cout << "Derived对象占几个字节：" << sizeof(Derived) << endl; // 40, 包含一份Base0的数据和两个父类中的指针数据
}
