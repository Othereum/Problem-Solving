// https://programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	const auto height{ triangle.size() };
	for (auto i{ 1u }; i < triangle.size(); ++i)
	{
		const auto width{ triangle[i].size() };
		for (auto j{ 0u }; j < width; ++j)
		{
			auto sum{ 0 };
			if (j > 0)
				sum = triangle[i][j] + triangle[i - 1][j - 1];
			if (j + 1 < width)
				sum = max(sum, triangle[i][j] + triangle[i - 1][j]);
			triangle[i][j] = sum;
		}
	}
	auto max{ 0 };
	for (auto x : triangle.back())
		if (x > max) max = x;
	return max;
}
