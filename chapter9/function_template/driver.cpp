/*
 * 练习函数模板
 */
#include <iostream>

using namespace std;

template <typename T>
T abs(T t)
{
	return t >= 0 ? t : -t; 
}

void test_typename()
{
	int i = 3, j = -5;
	double d1 = 4.5, d2 = -69.89;

	cout << i << " abs: " << abs(i) << endl;
	cout << j << " abs: " << abs(j) << endl;
	cout << d1 << " abs: " << abs(d1) << endl;
	cout << d2 << " abs: " << abs(d2) << endl;

}

template<class T>
void outputArray(const T *array, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

void test_class()
{
	int iArray[] = {1, 3, 5, 2, 7, 9, 10};
	char str[] = "hello, night.";

	outputArray(iArray, sizeof(iArray) / sizeof(int));
	outputArray(str, sizeof(str)/sizeof(char));
}

int main(int argc, char *argv[])
{
	test_typename();
	test_class();
	return 0;
}
