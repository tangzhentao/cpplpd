/*
 * 熟悉输入、输出和随机迭代器
 */
#include <iostream>
#include <vector>

using namespace std;

// 将来自输入迭代器p的n个T类型的数值排序，将结果通过输出迭代器result输出
template<class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
	vector<T> s;
	for(; first != last; ++first)
		s.push_back(*first);

	// 对s进行排序，sort函数的参数必须是随机访问迭代器
	sort(s.begin(), s.end());
	// 将s序列通过输出迭代器result输出
	copy(s.begin(), s.end(), result);
}

int main()
{
	double a[] = {1.2, 3.3, 0.8, 1, 3.6};
	int n = sizeof(a) / sizeof(double);
	cout << "a's size: " << n << endl;
	mySort<double>(a, a+n, ostream_iterator<double>(cout, " "));
	cout << endl;

	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " ") );
	cout << endl;
	return 0;
}
