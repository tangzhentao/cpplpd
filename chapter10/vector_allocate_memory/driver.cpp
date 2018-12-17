/*
 * 测试vector的内存申请策略
 *
 * 结论：
 * 初始化时有几个元素capacity就是几，没有元素时capacity为0
 * 当插入元素发现空间不够时，就会申请两倍于当前容量的空间
 */
#include <iostream>
#include <vector>

using namespace std;

void printVectorInfo(const vector<int> &v)
{
	cout << "vector, capacity: " << v.capacity() << ", size: " << v.size() << endl;
}

int main()
{
	vector<int> v(10, 3);
	printVectorInfo(v);

	int capacity = v.capacity();

	int cnt;
	cout << "vector number: ";
	cin >> cnt;
	for(int i = 0; i < cnt; i++)
	{
		v.push_back(i);
		if (capacity < v.capacity())
		{
			printVectorInfo(v);
			capacity = v.capacity();
		}
	}

	return 0;
}
