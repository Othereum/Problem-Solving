// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int reverse(int d)
{
	auto str{ to_string(d) };
	reverse(str.begin(), str.end());
	return stoi(str);
}

int main()
{
	int i, j, k;
	cin >> i >> j >> k;
	auto cnt{ 0 };
	for (auto d{ i }; d <= j; ++d)
		if (abs(d - reverse(d)) % k == 0)
			++cnt;
	cout << cnt;
}
