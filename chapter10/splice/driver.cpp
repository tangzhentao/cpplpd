/*
 * 拼接
 */
#include <iostream>
#include <list>
#include <string>

using namespace std;

template<class ElementType, class ContainerType>
void print(const char *msg, const ContainerType &s)
{
	cout << msg << endl;
	copy(s.begin(), s.end(), ostream_iterator<ElementType>(cout, " ") );
	cout << endl;
}

int main()
{
	string name1[] = {"hello", "world", "hi", "guy"};
	string name2[] = {"bod", "david", "tom", "sam"};
	list<string> s1(name1, name1+4);
	list<string> s2(name2, name2+4);

	// 打印两个链表的初始内容
	print<string>("init name1:", s1);
	print<string>("init name2:", s2);

	// 将s1的第一个元素放到s2最后
	s2.splice(s2.end(), s1, s1.begin());
	cout << endl;
	print<string>("spliced name1:", s1);
	print<string>("spliced name2:", s2);

	// 将s2中指定区间的元素拼接到s1中
	list<string>::iterator iter1 = s1.begin();
	advance(iter1, 2); // 将迭代器iter1前进2个元素，指向第三个元素
	list<string>::iterator iter2 = s2.begin();
	++iter2; // 前进一个元素
	list<string>::iterator iter3 = iter2;
	advance(iter3, 2);
	s1.splice(iter1, s2, iter2, iter3);
	cout << endl;
	print<string>("spliced name1:", s1);
	print<string>("spliced name2:", s2);

	return 0;
}
