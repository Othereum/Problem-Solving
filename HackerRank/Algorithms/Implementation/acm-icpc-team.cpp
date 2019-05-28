#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, int> acmTeam(const vector<string>& topic)
{
	const int s = topic.size(), nt = topic[0].size();
	int max = 0, cnt = 0;
	for (int i = 0; i < s; ++i)
	{
		for (int j = i + 1; j < s; ++j)
		{
			int c = 0;
			for (int k = 0; k < nt; ++k)
				if (topic[i][k] == '1' || topic[j][k] == '1')
					++c;
			if (c == max) ++cnt;
			else if (c > max)
			{
				max = c;
				cnt = 1;
			}
		}
	}
	return { max, cnt };
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> topic(n);
	for (string& t : topic)
		cin >> t;
	auto [max, cnt] = acmTeam(topic);
	cout << max << '\n' << cnt;
}
