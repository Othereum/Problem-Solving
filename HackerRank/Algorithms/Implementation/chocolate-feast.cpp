#include <iostream>
using namespace std;

int chocolateFeast(int n, int c, int m) 
{
	int chocolates = n / c, wrappers = chocolates;
	while (wrappers >= m)
	{
		const int newChocolates = wrappers / m;
		wrappers %= m;
		chocolates += newChocolates;
		wrappers += newChocolates;
	}
	return chocolates;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, c, m;
		cin >> n >> c >> m;
		cout << chocolateFeast(n, c, m) << '\n';
	}
}
