#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<string> neverHeard(N);
	for (string& name : neverHeard)
		cin >> name;

	vector<string> neverSeen(M);
	for (string& name : neverSeen)
		cin >> name;

	ranges::sort(neverHeard);
	ranges::sort(neverSeen);

	vector<string> answer;
	ranges::set_intersection(neverHeard, neverSeen, back_inserter(answer));

	cout << answer.size() << '\n';
	for (const string& name : answer)
		cout << name << '\n';
}
