/*
 * 例10-12
 * 熟悉多重映射multimap
 */
#include <iostream>
#include <map>

using namespace std;

typedef multimap<string, string>::iterator CourseIter;

int main()
{
	multimap<string, string> courses;
	// 课程表
	courses.insert(make_pair("c++", "2-6") );
	courses.insert(make_pair("os", "2-4") );
	courses.insert(make_pair("math", "1-1") );
	courses.insert(make_pair("c++", "4-2") );
	courses.insert(make_pair("c++", "5-6") );
	courses.insert(make_pair("os", "3-4") );
	courses.insert(make_pair("english", "3-6") );

	// 查询指定的课程每周有几节
	string name;
	int count;
	do
	{
		cin >> name;
		count = courses.count(name);
		if (0 == count)
			cout << "Cannot find " << name << " course." << endl;
	} while(0 == count);

	// 输出指定课程每周上课次数和上课时间
	cout << count << " lesson(s) per week:" << endl;
	pair<CourseIter, CourseIter> range = courses.equal_range(name);
	for(CourseIter i = range.first; i != range.second; i++)
		cout << i->second << " ";
	cout << endl;
	
	return 0;
}
