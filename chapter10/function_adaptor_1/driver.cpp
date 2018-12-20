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
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));

	vector<int>::iterator first = s.begin(), last = s.end();
	vector<int>::iterator iter = find_if(first, last, bind2nd(g, 40));

	cout << "检查迭代器first有没有被find_if改变" << endl;
	cout << "first element: " << *first << endl;

	return 0;
}
