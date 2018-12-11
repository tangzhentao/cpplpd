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
		// 赋值运算符重载
		Array &operator = (const Array &right);
		// 重载转换到“T *”的类型转换，是Array可以起到C++普通数组的作用
		operator T *(); 
		operator const T * ();

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
	cout << typeid(*this).name() << "::" << __func__ << endl;
	_list = new T[_size];
}

template<class T>
Array<T>::Array(const Array<T> &array)
{
	cout << typeid(*this).name() << "::" << __func__ << " copy" << endl;
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
	cout << typeid(*this).name() << "::" << __func__ << endl;
	delete[] _list;
}

template<class T>
T & Array<T>::operator [](int i)
{
	//cout << typeid(*this).name() << "::" << __func__ << endl;
	if(i >= _size || i < 0)
	{
		cout << "index(" << i << ")" << " out of bounds)" << _size << ")" << endl;
		exit(1);
	}

	return *(_list+i);
}

template<class T>
const T & Array<T>::operator [](int i) const
{
	//cout << typeid(*this).name() << "::" << __func__ << " const" << endl;
	if(i >= _size || i < 0)
	{
		cout << "index(" << i << ")" << " out of bounds)" << _size << ")" << endl;
		exit(1);
	}

	return *(_list+i);
}

template<class T>
Array<T> &Array<T>::operator = (const Array<T> &right)
{
	cout << typeid(*this).name() << "::" << __func__ << endl;
	// 检查right是不是自己
	if (this != &right) 
	{// 不是
		// 检查right的size是否与自己的size相同
		if (_size != right.getSize())
		{// 不同,则删除现在分配的内存，重新申请内存
			delete [] _list;
			_size = right.getSize();
			_list = new T[_size];
		}

		for (int i = 0; i < _size; i++)
		{
			*(_list+i) = right[i];
		}
	}

	return *this;
}

template<class T>
Array<T>::operator T * ()
{
	cout << typeid(*this).name() << "::" << __func__ << endl;
	return _list;
}

template<class T>
Array<T>::operator const T * ()
{
	
	cout << typeid(*this).name() << "::" << __func__ << " const" << endl;
	return _list;
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
