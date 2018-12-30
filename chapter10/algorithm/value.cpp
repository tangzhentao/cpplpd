/*
 * 例10-23
 * 数值算法示例
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	vector<int> s(a, a + sizeof(a)/sizeof(int));
	
	cout << "容器内元素的累积" << endl;
	int sum = accumulate(s.begin(), s.end(), 0);
	cout << "累加值为：" << sum << endl;

	cout << "hello" << endl;
	return 0;
}
