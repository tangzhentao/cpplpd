/*
 * 例10-16
 * 熟悉二元谓词函数对象
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a[] = {3, 9, 1, 4, 7, 5, 2};
	const int N = sizeof(a)/sizeof(int);
	vector<int> s(a, a+N);
	cout << "before sorting:" << endl;
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " ") );
	cout << endl;

	sort(s.begin(), s.end(), greater<int>() );

	cout << "after sorting:" << endl;
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " ") );
	cout << endl;

	return 0;
}
