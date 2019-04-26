// https://www.hackerrank.com/challenges/picking-numbers

#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map<int, int> NumOfInt;
	for (auto i{ 0 }; i < n; ++i)
	{
		int a;
		cin >> a;
		++NumOfInt[a];
	}
	auto cur{ NumOfInt.begin()->first };
	auto cnt{ 0 };
	auto max{ 0 };
	for (const auto& p : NumOfInt)
	{
		if (p.first - cur <= 1)
		{
			cnt += p.second;
		}
		else
		{
			cur = p.first;
			cnt = p.second;
		}
		if (cnt > max)
		{
			max = cnt;
		}
	}
	cout << max;
}
