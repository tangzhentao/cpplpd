/*
 * 熟悉deque
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	istream_iterator<int> begin(cin), end;
	vector<int> v(begin, end);
	sort(v.begin(), v.end());

	deque<int> d;
	for(vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		if (*i%2 == 0)
			d.push_back(*i);
		else
			d.push_front(*i);

	}

	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " ") );
	cout << endl;

	return 0;
}
