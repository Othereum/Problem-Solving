// https://www.hackerrank.com/challenges/electronics-shop
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int b, n, m;
	cin >> b >> n >> m;
	vector<int> keyboard(n), drives(m);
	for (auto& k : keyboard)
		cin >> k;
	for (auto& d : drives)
		cin >> d;
	auto max{ -1 };
	for (auto i{ 0 }; i < n; ++i)
	{
		for (auto j{ 0 }; j < m; ++j)
		{
			const auto sum{ keyboard[i] + drives[j] };
			if (sum > max && sum <= b) max = sum;
		}
	}
	cout << max;
}
