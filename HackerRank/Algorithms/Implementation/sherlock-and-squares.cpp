#include <iostream>
using namespace std;

int squares(const int a, const int b)
{
	auto cnt{ 0 };
	for (auto i{ 1 };; ++i)
	{
		const auto s{ i * i };
		if (a <= s)
		{
			if (s <= b) ++cnt;
			else break;
		}
	}
	return cnt;
}

int main()
{
	int t;
	cin >> t;
	for (auto i{ 0 }; i < t; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << squares(a, b) << '\n';
	}
}
