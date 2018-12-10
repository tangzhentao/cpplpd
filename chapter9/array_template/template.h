#include <iostream>

using namespace std; 

template<class T>
class Array
{
	public:
		// 默认构造函数，默认size为10
		Array(int size = 10);
		// 必要的析构函数，因为有动态分配的内存
		~Array();
		// 赋值构造函数
		Array(const Array &a);
		// 数组下标运算符重载
		T &operator [](int i);
		// 数组下标运算符重载，针对const类型的重载
		const T &operator [](int i) const;

		// 获取size
		int getSize() const;
		// 重新分配size
		void resize(int size);

	private:
		T *_list;
		int _size;
};

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
