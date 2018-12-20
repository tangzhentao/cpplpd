/*
 * 例10-17
 * 体验函数适配器——绑定适配器
 */
#include <iostream>
#include <vector>

using namespace std;

bool greaterThan40(int x)
{
	return x > 40;
}

int main()
{
	int a[] = {20, 30, 80, 10, 50, 90, 40};
	const int N = sizeof(a)/sizeof(int);
	vector<int> s(a, a+N);
	
	cout << "使用普通函数作为一元谓词函数" << endl;
	vector<int>::iterator iter = find_if(s.begin(), s.end(), greaterThan40 );
	if (iter == s.end())
	{
		cout << "not found." << endl;
	} else 
	{
		cout << "found " << *iter << endl;
	}
	cout << "使用普通函数作为一元谓词函数" << endl;
	iter = find_if(s.begin(), s.end(), bind2nd(greater<int>(), 80));
	if (iter == s.end())
	{
		cout << "not found." << endl;
	} else 
	{
		cout << "found " << *iter << endl;
	}

	return 0;
}
