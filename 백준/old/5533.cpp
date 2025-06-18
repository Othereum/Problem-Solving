// https://www.acmicpc.net/problem/5533

#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>

using namespace std;

int main()
{
	static constexpr auto NumGames = 3;

	int NumPeople;
	cin >> NumPeople;

	vector<array<int, NumGames>> WroteNums(NumPeople);
	for (auto& Person : WroteNums)
		for (auto& WroteNum : Person)
			cin >> WroteNum;

	array<unordered_multiset<int>, NumGames> game;

	for (auto& Person : WroteNums)
		for (int i = 0; i < NumGames; ++i)
			game[i].insert(Person[i]);

	vector<int> scores(NumPeople);

	for (int p = 0; p < NumPeople; ++p)
		for (int g = 0; g < NumGames; ++g)
			if (game[g].count(WroteNums[p][g]) == 1)
				scores[p] += WroteNums[p][g];

	for (int s : scores)
		cout << s << '\n';
}
