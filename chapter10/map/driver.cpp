/*
 * 例10-10
 * 映射map
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> courses;

	courses.insert(make_pair("csapp", 3));
	courses.insert(make_pair("c++", 4));
	courses.insert(make_pair("os", 2));
	courses.insert(make_pair("math", 5));
	courses.insert(make_pair("english", 3));

	int n = 3;
	int sum = 0;
	while(n > 0)
	{
		string name;
		cin>> name;
		map<string, int>::iterator iter = courses.find(name);
		if (iter == courses.end())
		{
			// 没有找到
			cout << name << " is not available" << endl;
		} else {
			sum += iter->second;
			courses.erase(iter);
			n--;
		}
	}

	cout << "Total credit: " << sum << endl;

	return 0;
}
