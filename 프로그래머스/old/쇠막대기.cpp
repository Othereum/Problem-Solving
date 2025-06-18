// https://programmers.co.kr/learn/courses/30/lessons/42585

#include <string>
#include <vector>

using namespace std;

int solution(const string arrangement)
{
	auto answer = 0;
	vector<int> pieces;
	auto last = '\0';
	for (auto c : arrangement)
	{
		if (c == '(')
		{
			if (last == '(') pieces.push_back(1);
		}
		else
		{
			if (last == '(') for (auto& n : pieces) ++n;
			else
			{
				answer += pieces.back();
				pieces.pop_back();
			}
		}
		last = c;
	}
	return answer;
}
