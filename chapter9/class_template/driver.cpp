/*
 * 练习类模板
 */
#include <iostream>

using namespace std;

struct Student 
{
	string name;
	int age;
};

template<class T>
class Store
{
	public:
		Store();
		const T & getElement() const;
		void putElement(T element);
	
	private:
		bool _haveValue;
		T _data;
};

template<class T>
Store<T>::Store(): _haveValue(false)
{
}

template<class T>
const T & Store<T>::getElement() const
{
	if (!_haveValue)
	{
		cout << "no store in store!" << endl;
		exit(1);
	}

	return _data;
}

template<class T>
void Store<T>::putElement(T element)
{
	_haveValue = true;
	_data = element;
}

int main()
{
	int i = 10, j = -99;
	Store<int> iStore;
	iStore.putElement(i);
	cout << "iStore: " << iStore.getElement() << endl; 
	iStore.putElement(j);
	cout << "iStore: " << iStore.getElement() << endl; 

	double d1 = 8.99;
	Store<double> dStore;
	dStore.putElement(d1);
	cout << "dStore: " << dStore.getElement() << endl; 

	Student s = {"jing", 22};
	Store<Student> sStore;
	sStore.putElement(s);
	cout << "sStore: " << sStore.getElement().name << ", " << sStore.getElement().age << endl; 

	return 0;
}
