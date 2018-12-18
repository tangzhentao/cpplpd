/*
 * 容器适配器——栈
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<char> s;
	string str;
	cin >> str;

	for(string::iterator i = str.begin(); i != str.end(); i++)
	{
		s.push(*i);
	}

	while(!s.empty() )
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;

	return 0;
}
