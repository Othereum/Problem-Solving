// https://www.hackerrank.com/challenges/breaking-best-and-worst-records
#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int max, min; cin >> min; max = min;
	int maxCnt{}, minCnt{};
	for (int i{1}; i < n; ++i)
	{
		int a;
		cin >> a;
		if (a > max)
		{
			max = a;
			++maxCnt;
		}
		else if (a < min)
		{
			min = a;
			++minCnt;
		}
	}
	cout << maxCnt << ' ' << minCnt;
}