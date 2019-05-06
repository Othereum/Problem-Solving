// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T Next() { T t; cin >> t; return t; }

int main()
{
	const auto n{ Next<int>() }, k{ Next<int>() };
	const auto c{ [n] {vector<bool>c; c.reserve(n); for (auto i{0}; i < n; ++i)c.push_back(Next<bool>()); return c; }() };
	auto i{ 0 }, e{ 100 };
	do
	{
		i = (i + k) % n;
		e -= c[i] ? 3 : 1;
	} while (i != 0);
	cout << e;
}
