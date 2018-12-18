/*
 * 例10-11
 *
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char, int>s;
	char c;
	do 
	{
		cin >> c;
		if (isalpha(c))
		{
			c = tolower(c);
			s[c]++;
		}
	} while(c != '.');

	for (map<char, int>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << i->first << ": " << i->second << endl;
	}
	cout << "hello" << endl;
	return 0;
}
