// https://www.hackerrank.com/challenges/find-digits

#include <iostream>
#include <string>
using namespace std;

template <typename T>
T Next() { T t; cin >> t; return t; }

int main()
{
	for (auto t{ Next<int>() }; t > 0; --t)
	{
		const auto s{ Next<string>() };
		const auto n{ stoi(s) };
		auto cnt{ 0 };
		for (auto c : s)
		{
			const auto d{ c - '0' };
			if (d != 0 && n % d == 0)
				++cnt;
		}
		cout << cnt << '\n';
	}
}
