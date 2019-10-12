#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(const vector<int> array, const vector<vector<int>> commands)
{
	vector<int> answers;
	answers.reserve(commands.size());
	
	for (auto& cmd : commands)
	{
		vector<int> v(array.data() + cmd[0] - 1, array.data() + cmd[1]);
		sort(v.begin(), v.end());
		answers.push_back(v[cmd[2]-1]);
	}

	return answers;
}
