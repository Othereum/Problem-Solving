// https://www.hackerrank.com/challenges/utopian-tree
#include <iostream>
using namespace std;
int main()
{
	int t; cin >> t;
	for (auto i{ 0 }; i < t; ++i)
	{
		int n; cin >> n;
		auto h{ 1 }; auto bPlus{ false };
		for (auto j{ 0 }; j < n; ++j)
		{
			if (bPlus) ++h; else h *= 2;
			bPlus = !bPlus;
		}
		cout << h << '\n';
	}
}
