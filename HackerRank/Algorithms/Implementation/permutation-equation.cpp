// https://www.hackerrank.com/challenges/permutation-equation

#include <iostream>
#include <map>
using namespace std;

template <typename T>
T Next() { T t; cin >> t; return t; }

int main()
{
	const auto n{ Next<int>() };
	const auto p{ [n] {
		map<int, int> p;
		for (auto i{ 1 }; i <= n; ++i)
			p.emplace(Next<int>(), i);
		return p;
	}() };
	for (auto i{ 1 }; i <= n; ++i)
		cout << p.at(p.at(i)) << '\n';
}
