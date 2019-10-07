#include <algorithm>
#include <vector>

int solution(const int n, std::vector<int> lost, std::vector<int> reserve)
{
	std::vector<int> arr(n, 1);
	for (const auto i : lost) --arr[i-1];
	for (const auto i : reserve) ++arr[i-1];
	for (auto i = 0; i < n; ++i)
	{
		if (arr[i] >= 2 && 0 <= i-1 && arr[i-1] == 0)
		{
			++arr[i-1];
			--arr[i];
		}
		if (arr[i] >= 2 && i+1 < n && arr[i+1] == 0)
		{
			++arr[i+1];
			--arr[i];
		}
	}
	return std::count_if(arr.begin(), arr.end(), [](const auto x){return x > 0;});
}
