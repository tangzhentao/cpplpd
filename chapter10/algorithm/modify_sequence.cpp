/*
 * 例10-21
 * 熟悉可变序列算法
 */
#include <iostream>
#include <vector>

using namespace std;

class evenByTwo
{
public:
	evenByTwo(): x(0) {}
	int operator() () {return x += 2;}

private:
	int x;
};

int main()
{
	int a1[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 7, 8, 9};
	int a2[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9};
	vector<int> s1(a1, a1 + sizeof(a1)/sizeof(int));
	vector<int> s2(a2, a2 + sizeof(a2)/sizeof(int));
	vector<int> s3(2);
	ostream_iterator<int> output(cout, " ");

	// 迭代遍历s3区间，每个元素填上-1
	fill(s3.begin(), s3.end(), -1);
	copy(s3.begin(), s3.end(), output);
	cout << endl;

	// 迭代遍历s3区间，对每一个元素进行evenByTwo操作
	generate(s3.begin(), s3.end(), evenByTwo());
	copy(s3.begin(), s3.end(), output);
	cout << endl;

	// 将删除元素6后的s2序列置于另一个容器s4中
	vector<int> s4;
	remove_copy(s1.begin(), s1.end(), back_inserter(s4), 6);
	copy(s4.begin(), s4.end(), output);
	cout << endl;

	// 删除s2中小于6的元素
	s2.erase(remove_if(s2.begin(), s2.end(), bind2nd(less<int>(), 6)), s2.end());
	copy(s2.begin(), s2.end(), output);
	cout << endl;

	// 将所有值为6的元素的值改为3
	replace(s2.begin(), s2.end(), 6, 3);
	copy(s2.begin(), s2.end(), output);
	cout << endl;

	// 逆向重排每一个元素
	reverse(s2.begin(), s2.end());
	copy(s2.begin(), s2.end(), output);
	cout << endl;

	// 互换两个区间的元素并输出
	rotate_copy(s2.begin(), s2.begin()+3, s2.end(), output);
	cout << endl;
	return 0;
}
