#include <vector>

using namespace std;

vector<int> solution(const vector<int> arr) 
{
    vector<int> answer;
	auto last = -1;

	for (const auto x : arr)
	{
		if (x != last)
		{
			last = x;
			answer.push_back(x);
		}
	}

    return answer;
}
