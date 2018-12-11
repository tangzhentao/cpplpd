/*
 * 测试驱动程序
 */
#include <iostream>
#include "template.h"

using namespace std;

template<class T>
void printArray(const Array<T> &array)
{
	int size = array.getSize();
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main()
{
	Array<int> iArray(10);
	printArray (iArray);
	for(int i = 0; i < iArray.getSize(); i++)
	{
		iArray[i] = i;
	}
	printArray (iArray);

	Array<double> dArray(10);
	printArray (dArray);
	for(int i = 0; i < dArray.getSize(); i++)
	{
		dArray[i] = i * 0.5;
	}
	printArray (dArray);

	Array<char> sArray(10);
	printArray (sArray);
	for(int i = 0; i < sArray.getSize(); i++)
	{
		sArray[i] = i + 70;
	}
	printArray (sArray);

	cout << "test copy constructor." << endl;
	Array<int> iArray2(iArray);
	printArray(iArray2);
	cout << endl;

	cout << "test const operator []" << endl;
	const Array<int> &const_array = iArray;
	cout << "index 0: " << const_array[0];

	// const_array[0] = 10; // compile error
	cout << endl;

	cout << "test operator =" << endl;
	Array<int> iArray3;
	iArray3 = iArray;
	printArray(iArray3);
	cout << endl;

	cout << "test operator T *" << endl;
	int *iptr = iArray3;
	for (int i = 0; i < iArray3.getSize(); i++)
	{
		cout << iptr[i] << " ";
	}
	cout << endl;

	return 0;
}
