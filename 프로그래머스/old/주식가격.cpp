// https://programmers.co.kr/learn/courses/30/lessons/42584

#include <vector>

using namespace std;

vector<int> solution(const vector<int> prices)
{
    vector<int> answer(prices.size());

	for (size_t i = 0; i < prices.size(); ++i)
	{
		for (auto j = i + 1; j < prices.size(); ++j)
		{
			++answer[i];
			if (prices[i] > prices[j]) break;
		}
	}
	
    return answer;
}
