// https://www.hackerrank.com/challenges/drawing-book

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;
	vector<pair<int, int>> book;
	book.reserve(n / 2 + 1);
	book.emplace_back(0, 1);
	for (int i{ 2 }; i <= n; ++i)
	{
		book.emplace_back();
		auto& pages{ book.back() };
		pages.first = i;
		if (++i <= n) pages.second = i;
	}
	int fCnt{};
	for (auto it{ book.cbegin() }; it != book.cend(); ++it)
	{
		if (it->first == p || it->second == p) break;
		++fCnt;
	}
	int bCnt{};
	for (auto it{ book.crbegin() }; it != book.crend(); ++it)
	{
		if (it->first == p || it->second == p) break;
		++bCnt;
	}
	cout << (fCnt < bCnt ? fCnt : bCnt);
}
