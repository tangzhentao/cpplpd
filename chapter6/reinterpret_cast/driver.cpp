/*
 * 练习指针类型转换 reinterpret_cast
 */
#include <iostream>

using namespace std;

int main()
{
	int i = 10;
	int *intPtr = &i;
	cout << "*intPtr: " << intPtr << ", " << *intPtr << endl;
	float *floatPtr = reinterpret_cast<float *>(intPtr);
	cout << "*floatPtr: " << floatPtr << ", " << *floatPtr << endl;
	return 0;
}
