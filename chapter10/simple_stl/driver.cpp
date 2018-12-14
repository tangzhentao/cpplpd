/*
 * 一个简单的STL程序
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	const int N = 5;
	vector<int> s(N);

	for(int i = 0; i < N; i++)
	{
		cin >> s[i];
	}

	transform(s.begin(), s.end(), ostream_iterator<int>(cout, " "), negate<int>() );
	cout << endl;
	return 0;
}
