#include "template.h"
#include <iostream>

using namespace std; 

template<class T>
Array<T>::Array(int size): _size(size)
{
	_list = new T[_size];
}

template<class T>
Array<T>::Array(const Array<T> &array)
{
	// 申请空间
	_size = array.getSize();
	_list = new T[_size];
	
	// 复制值
	for(int i = 0; i < _size; i++)
	{
		*(_list+i) = array[i];
	}
}

template<class T>
Array<T>::~Array()
{
	delete[] _list;
}

template<class T>
T & Array<T>::operator [](int i)
{
	if(i >= _size || i <= 0)
	{
		cout << "index out of bounds: " << i << endl;
		exit(1);
	}

	return *(_list+i);
}

template<class T>
const T & Array<T>::operator [](int i) const
{
	if(i >= _size || i <= 0)
	{
		cout << "index out of bounds: " << i << endl;
		exit(1);
	}

	return *(_list+i);
}

template<class T>
int Array<T>::getSize() const
{
	return _size;
}

template<class T>
void Array<T>::resize(int size)
{
	cout << "resize " << endl;
}
