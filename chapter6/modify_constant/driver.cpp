/*
 * 测试通过指针变量能不能修改常量的值
 *
 * 结论：
 * 不能，即使通过强转指针类型修改指针所指地址中的值也无法修改常量的值。
 * 疑问：为什么常量所在内存中的值已经修改还无法修改常量的值呢？
 * 分析：可能编译器把出现常量的地方是替换为常量的值了，不是去内存中取的值;
 */
#include <iostream>

using namespace std;

int main()
{
	const int i = 10;

	cout << "1. 常量i = " << i << endl;
	const int *iptr = &i;
	cout << "2. *iptr = " << *iptr << endl;
	int *ptr = (int *)iptr; 
	*ptr = 20;
	cout << "3. 常量i = " << i << endl;
	cout << "4. *ptr = " << *ptr << endl;
	cout << "5. *iptr = " << *iptr << endl;
	cout << "6. 常量i = " << *(&i) << endl;

	cout << "7. i的地址：" << &i << ", iptr: " << iptr << ", ptr: " << ptr << endl;
	return 0;
}
