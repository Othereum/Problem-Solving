#include <cmath>
#include <iostream>

using namespace std;

// 완전 탐색: 가능한 모든 조합의 제곱수를 더해본다
int powerSum(const int x, const int n, int s = 0, int a = 0)
{
	// 기저 사례: 합이 X와 같으면 하나의 경우가 성립
	if (x == s) return 1;

	int f, cnt = 0;
	while (x >= (f = s + pow(++a, n)))
		cnt += powerSum(x, n, f, a);
	return cnt;
}

int main()
{
	int x, n;
	cin >> x >> n;
	cout << powerSum(x, n);
}
