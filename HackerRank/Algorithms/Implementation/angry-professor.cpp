// https://www.hackerrank.com/challenges/angry-professor
#include <iostream>
using namespace std;
int main()
{
	int t; cin >> t;
	for (auto i{ 0 }; i < t; ++i)
	{
		int n, k;
		cin >> n >> k;
		auto cnt{ 0 };
		for (auto j{ 0 }; j < n; ++j)
		{
			int a; cin >> a;
			if (a <= 0) ++cnt;
		}
		cout << (cnt < k ? "YES" : "NO") << '\n';
	}
}
