// https://www.hackerrank.com/challenges/append-and-delete

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<class T>
auto GetFirstDiffIdx(const T& a, const T& b)
{
	const auto l{ min(a.size(), b.size()) };
	typename T::size_type i{};
	for (; i < l && a[i] == b[i]; ++i);
	return i;
}

template<class T>
T Next() { T t; cin >> t; return t; }

int main()
{
	const auto s{ Next<string>() };
	const auto t{ Next<string>() };
	const auto k{ Next<string::size_type>() };
	const auto i{ GetFirstDiffIdx(s, t) };
	const auto MinOp{ (s.size() - i) + (t.size() - i) };
	const auto LeftOp{ k - MinOp };
	cout << (MinOp <= k && (LeftOp % 2 == 0 || LeftOp > i * 2) ? "Yes" : "No");
}
