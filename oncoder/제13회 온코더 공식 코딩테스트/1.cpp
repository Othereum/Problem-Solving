// https://www.oncoder.com/developer/score-detail/SyTKZzp3E

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int solution(vector<int> apples)
	{
		sort(apples.begin(), apples.end());
		auto Max{ 0 };
		for (auto i{ 0 }; i < apples.size(); ++i)
			Max = max<int>(Max, apples[i] * (apples.size() - i));
		return Max;
	}
};
