/*
 * 体验逆向迭代器
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> s;
	for(int i = 0; i < 10; i++)
		s.push_back(i);

	copy(s.rbegin(), s.rend(), ostream_iterator<int>(cout, " ") );
	cout << endl;
	cout << "hello" << endl;
	return 0;
}
