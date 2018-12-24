/*
 * 例10-20
 * 熟悉不可变序列算法
 */
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 6, 7, 8};
	vector<int> s(a, a + sizeof(a)/sizeof(int) );

	int a1[] = {6, 6};
	vector<int> s1(a1, a1 + sizeof(a1)/sizeof(int) );

	int a2[] = {5, 6};
	vector<int> s2(a2, a2 + sizeof(a2)/sizeof(int) );

	int a3[] = {0, 1, 2, 3, 4, 5, 7, 7, 7, 8};
	vector<int> s3(a3, a3 + sizeof(a3)/sizeof(int) );

	cout << "找出s中相邻元素值相等的第一个元素" << endl;
	cout << *adjacent_find(s.begin(), s.end()) << endl;

	cout << "找出s中小于7的元素个数" << endl;
	cout << count_if(s.begin(), s.end(), bind2nd(less<int>(), 7) ) << endl;
	
	cout << "找出s中大于2的第一个元素" << endl;
	cout << *find_if(s.begin(), s.end(), bind2nd(greater<int>(), 2) ) << endl;;

	cout << "子序列s2在s宗出现的起点位置元素" << endl;
	cout << *search(s.begin(), s.end(), s2.begin(), s2.end() ) << endl;
	
	cout << "查找连续出现3个6的起点位置元素" << endl;
	cout << *search_n(s.begin(), s.end(), 3, 6) << endl;

	cout << "判断两个区间s和s3是否相等(0为假，1为真)" << endl;
	cout << equal(s.begin(), s.end(), s3.begin()) << endl;
	cout << "查找区间s3在s中不匹配点的位置" << endl;
	pair<vector<int>::iterator, vector<int>::iterator> result = 
		mismatch(s.begin(), s.end(), s3.begin());
	//cout << *result.first << ", " << *(result.second) << endl;
	cout << result.first - s.begin() << endl;

	return 0;
}
