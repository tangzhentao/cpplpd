/*
 * 熟悉标准模板库中的set
 * 例10-9
 */
#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<double> s;
	while(true)
	{
		double v;
		cin >> v;
		if (0 == v)
		{
			// 结束输入
			break;
		}

		pair<set<double>::iterator, bool> result = s.insert(v);
		if (!result.second)
		{
			// 插入失败
			cout << v << " is duplicated" << endl;
		}

	}
	set<double>::iterator iter1 = s.begin();
	set<double>::iterator iter2 = s.end();
	double medium = (*iter1 + *(--iter2)) / 2;
	cout << "medium = " << medium << endl;
	cout << "<=medium: ";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " ") );
	cout << endl;

	cout << ">=medium: ";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " ") );
	cout << endl;

	return 0;
}
