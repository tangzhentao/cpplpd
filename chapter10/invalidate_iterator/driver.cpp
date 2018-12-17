/*
 * 查看失效的迭代器
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.reserve(3);
	v.push_back(1);
	v.push_back(2);

	vector<int>::iterator iter1 = v.begin();
	int *p1 = &v[0];
	vector<int>::iterator iter2 = v.begin()+1;
	int *p2 = &v[1];
	v.insert(v.begin()+1, 3);

	cout << *iter1 << " " << *p1 << endl;
	cout << *iter2 << " " << *p2 << endl;

	return 0;
}
