// https://www.hackerrank.com/challenges/between-two-sets

#include <iostream>
using namespace std;

template <class T>
constexpr T gcd(T a, T b)
{
	T c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

template <class T>
constexpr T lcm(T a, T b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int n, m;
	cin >> n >> m;

    // 1. a[]의 최소 공배수 a_lcm을 구함
	int a_lcm;
	cin >> a_lcm;
	for (int i = 1; i < n; ++i)
	{
		int t;
		cin >> t;
		a_lcm = lcm(a_lcm, t);
	}

    // 2. b[]의 최대 공약수 b_gcd를 구함
	int b_gcd;
	cin >> b_gcd;
	for (int i = 1; i < m; ++i)
	{
		int t;
		cin >> t;
		b_gcd = gcd(b_gcd, t);
	}

    // 3. a_lcm의 배수 중에서 b_gcd의 약수가 되는 수의 개수가 정답
	int cnt = 0;
	for (int m = a_lcm; m <= b_gcd; m += a_lcm)
		if (b_gcd % m == 0) ++cnt;
	cout << cnt;
}
