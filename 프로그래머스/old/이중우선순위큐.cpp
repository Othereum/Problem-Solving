#include <set>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(const vector<string> operations)
{
	multiset<int> q;
	for (auto&& op : operations)
	{
		if (op[0] == 'I')
		{
			q.insert(atoi(op.data() + 2));
		}
		else if (op[2] == '-')
		{
			if (!q.empty()) q.erase(q.begin());
		}
		else
		{
			if (!q.empty()) q.erase(prev(q.end()));
		}
	}
	
	if (q.empty()) return {0, 0};
	return {*prev(q.end()), *q.begin()};
}
