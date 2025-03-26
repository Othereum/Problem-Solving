#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	unordered_set<int> S;
	vector<int> V(N);
	for (int& x : V)
	{
		cin >> x;
		S.insert(x);
	}

	vector<int> S0(S.begin(), S.end());
	ranges::sort(S0);
	
	unordered_map<int, int> S1;
	for (int i = 0; i < S0.size(); i++)
		S1[S0[i]] = i;

	for (int x : V)
		cout << S1[x] << ' ';
}
