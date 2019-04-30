// https://algospot.com/judge/problem/read/FESTIVAL

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	int c;
	cin >> c;
    cout << fixed;
    cout.precision(11);
	for (auto i = 0; i < c; ++i)
	{
		int n, l;
		cin >> n >> l;
		vector<int> arr(n);
		for (auto& a : arr)
			cin >> a;
		auto min = static_cast<double>(accumulate(&arr[0], &arr[l], 0)) / l;
		for (auto j = 0; j + l <= n; ++j)
		{
			auto sum = accumulate(&arr[j], &arr[j + l - 1], 0);
			for (auto k = j + l - 1; k < n; ++k)
			{
				sum += arr[k];
				const auto avg = static_cast<double>(sum) / (k - j + 1);
				if (avg < min)
				{
					min = avg;
				}
			}
		}
		cout << min << '\n';
	}
}
