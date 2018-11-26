/*
 * 通过练习熟悉指向类成员的指针
 */
#include <iostream>

using namespace std;

class foo
{
	public:
		string name;
		int data1;
		int data2;

		void print ()
		{
			cout << "data1: " << data1 << ", data2: " << endl;
		}

	private:
		int data3;
};

int main()
{
	foo f;
	f.data1 = 5;
	f.data2 = 10;
	int foo::* dataPtr;
	cout << "dataPtr: " << dataPtr << endl;
	dataPtr = &foo::data1;
	cout << "dataPtr: " << dataPtr << endl;
	cout << "f.*dataPtr: " << f.*dataPtr << endl;
	
	cout << "dataPtr: " << dataPtr << endl;
	dataPtr = &foo::data2;
	cout << "dataPtr: " << dataPtr << endl;
	cout << "f.*dataPtr: " << f.*dataPtr << endl;

	return 0;
}
