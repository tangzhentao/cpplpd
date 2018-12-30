/*
 * 例10-22
 * 熟悉排序和搜索
 */
#include <iostream>
#include <vector>


using namespace std;

void print(vector<int> s)
{
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main()
{
	int a[] = {26, 17, 15, 22, 23, 33, 32, 40};
	vector<int> s(a, a + sizeof(a)/sizeof(int));

	// 查找并输出第一个最大值元素及其位置
	vector<int>::iterator p = max_element(s.begin(), s.end());
	int n = p - s.begin();
	cout << "max element: " << *p << ", position: " << n << endl;

	// 局部排序并复制到别处
	vector<int> s1(5);
	partial_sort_copy(s.begin(), s.end(), s1.begin(), s1.end());
	copy(s1.begin(), s1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	// 查看原有容器s中的元素顺序有没有改变
	cout << "s:" << endl;
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// 排序，默认为递增
	sort(s.begin(), s.end());
	cout << "sorted s:" << endl;
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	int base = 23;
	vector<int>::iterator iterLower = lower_bound(s.begin(), s.end(), base);
	vector<int>::iterator iterUpper = upper_bound(s.begin(), s.end(), base);
	cout << "第一个不小于" << base << "的元素：" << *iterLower << " position: " << iterLower - s.begin() << endl;
	cout << "第一个大于" << base << "的元素：" << *iterUpper << " position: " << iterUpper- s.begin() << endl;

	int numTofind = 33;
	bool exist = binary_search(s.begin(), s.end(), numTofind);
	cout << "Does " << numTofind << " exist ? " << boolalpha << exist << endl;

	cout << "合并两个序列s和s1，并将结果放倒s2中" << endl;
	vector<int> s2(13);
	merge(s.begin(), s.end(), s1.begin(), s1.end(), s2.begin());
	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	int a3[] = {2, 0, 3, 1, 4, 5, 2, 6, 9, 8};
	vector<int> s3(a3, a3 + sizeof(a3)/sizeof(int));
	vector<int>::iterator baseIter = s3.begin() ;//+ 2;
	cout << "将小于" << *baseIter << "的元素放置在该元素之左，其余元素放置在该元素之右(不保证维持原有的相对位置)" << endl;
	cout << "操作前序列:" << endl;
	print(s3);
	nth_element(s3.begin(), baseIter, s3.end());
	cout << "操作后序列：" << endl;
	print(s3);

	cout << "排序，并保持原来相对位置" << endl;
	vector<int> s4(a3, a3 + sizeof(a3)/sizeof(int));
	cout << "排序前序列：" << endl;
	print(s4);
	stable_sort(s4.begin(), s4.end());
	cout << "排序后序列：" << endl;
	print(s4);

	cout << "原地合并，将两端有序的区间合并原地存储" << endl;
	int a5[] = {1, 3, 5, 2, 4, 6, 8};
	vector<int> s5(a5, a5 + sizeof(a5)/sizeof(int));
	cout << "原地合并前序列：" << endl;
	print(s5);
	inplace_merge(s5.begin(), s5.begin() + 3, s5.end());
	cout << "原地合并后序列：" << endl;
	print(s5);

	cout << "以字典序比较序列s5和s6" << endl;
	int a6[] = {1, 3, 5, 7, 1, 5, 9, 3};
	vector<int> s6(a6, a6 + sizeof(a6)/sizeof(int));
	bool comp = lexicographical_compare(s5.begin(), s5.end(), s6.begin(), s6.end());
	cout << comp << endl;
	return 0;
}
