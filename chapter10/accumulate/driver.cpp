/*
 * 熟悉accumulate
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	const int N = sizeof(a)/sizeof(int);
	int sum = accumulate(a, a + N, 0);
	cout << "sum: " << sum << endl; // 21

	sum = accumulate(a, a + N, 1, multiply); // 720
	cout << "sum: " << sum << endl;

	return 0;
}
