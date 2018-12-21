/*
 * 例10-18
 * 指针函数适配器、组合适配器
 */
#include <iostream>
#include <vector>

using namespace std;

bool g(int x, int y)
{
	return x > y;
}

int main()
{
	int a[] = {30, 10, 60, 80, 20, 90};
	const int N = sizeof(a) / sizeof(int);
	vector<int> s(a, a+N);

	// 打印向量s的元素
	cout << "向量s中的元素：" << endl;
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


	int iToFind;
	bool found = false;
	do 
	{
		cout << "输入一个基数: ";
		cin >> iToFind;
		vector<int>::iterator first = s.begin(), last = s.end();
		vector<int>::iterator iter = find_if(first, last, bind2nd(ptr_fun(g), iToFind));
		if (iter == last)
		{
			cout << "没有找到比40大的元素" << endl;
		} else
		{
			found = true;
			cout << "第一比 " << iToFind << " 大的元素是 " << *iter << endl;
		}

		cout << "检查迭代器first有没有被find_if改变" << endl;
		cout << "first element: " << *first << endl;
	} while(false == found);

	vector<int>::iterator iter = find_if(s.begin(), s.end(), not1( bind2nd(greater<int>(), 15) ) );
	if (iter == s.end()) 
	{
		cout << "没有找到不大于15的元素" << endl;
	} else 
	{
		cout << "第一个不大于15的元素是" << *iter << endl;
	}


	return 0;
}
