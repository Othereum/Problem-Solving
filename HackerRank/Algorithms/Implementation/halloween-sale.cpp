#include <algorithm>
#include <iostream>
using namespace std;

int howManyGames(int p, int d, int m, int s)
{
	int cnt = 0;
	for (int c = p + d; (s -= (c = max(m, c - d))) >= 0; ++cnt);
	return cnt;
}

int main()
{
	int p, d, m, s;
	cin >> p >> d >> m >> s;
	cout << howManyGames(p, d, m, s);
}
