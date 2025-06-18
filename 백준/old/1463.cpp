#include <climits>
#include <cstring>
#include <iostream>
#include <utility>

static int CACHE[1000000];
int solve(int x)
{
	if (x == 1) return 0;
	
	int& ret = CACHE[x - 1];
	if (ret != -1) return ret;

	int cnt = INT_MAX;
	if (x % 3 == 0)
		cnt = std::min(cnt, solve(x / 3));
	if (x % 2 == 0)
		cnt = std::min(cnt, solve(x / 2));

	cnt = std::min(cnt, solve(x - 1));

	return ret = cnt + 1;
}

int main()
{
	std::memset(CACHE, 0xFF, sizeof(CACHE));

	int N;
	std::cin >> N;
	std::cout << solve(N);
}
