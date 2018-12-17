/*
 * 熟悉STL容器基本操作
 */
#include <iostream>
#include <list>
#include <deque>
//#include <>

using namespace std;

template<class ElementType , class ContainerType>
void printContainer(const char *msg, const ContainerType &c)
{
	cout << msg << ": ";
	copy(c.begin(), c.end(), ostream_iterator<ElementType>(cout, " ") );
	cout << endl;
}

int main()
{
	// 从标准输入读入10个整型，将它们分别从s的头部加入
	deque<int> d;
	for (istream_iterator<int> iter(cin); iter != istream_iterator<int> (); iter++)
	{
		d.push_front(*iter);
	}

	/*
	for(int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		d.push_front(x);
	}
	*/
	printContainer<int>("first deque", d);

	// 用d容器的内容逆序构造容器l
	list<int> l(d.rbegin(), d.rend());
	printContainer<int>("first list", l);

	// 将列表容器l中相邻的两个元素交换顺序
	list<int>::iterator iter = l.begin();
	while(iter != l.end())
	{
		int v = *iter;
		iter = l.erase(iter);
		l.insert(++iter, v);
		cout << "swap" << endl;
	}
	printContainer<int>("swap element", l);

	// 用列表容器l的内容给d赋值，将d输出
	d.assign(l.begin(), l.end());
	printContainer<int>("assign deque", d);

	return 0;
}
