// https://www.hackerrank.com/challenges/the-birthday-bar

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned n;
	cin >> n;
	vector<unsigned> arr(n);
	for (unsigned& a : arr)
		cin >> a;
	unsigned d, m;
	cin >> d >> m;
	unsigned cnt{};
	for (unsigned i{}; i <= n - m; ++i)
	{
		unsigned sum{};
		for (unsigned j{ i }; j < i + m; ++j)
			sum += arr[j];
		if (sum == d) ++cnt;
	}
	cout << cnt;
}
