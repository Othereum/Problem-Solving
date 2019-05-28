// http://codeup.kr/problem.php?id=3025

#include <iostream>
#include <vector>
using namespace std;

// 기본적으로 DP 문제
// C[i]는 x^(i+1) 항의 계수를 나타냄
// x 부터 시작해 (x+1), (x+2), ..., (x+r) 차례대로 곱해나감
vector<long long> PolynomialExpansion(int n)
{
	vector<long long> C(n);
	C[0] = 1;
	for (int r = 1; r < n; ++r)
	{
		C[r] = 1;
		for (int i = r - 1; i > 0; --i)
			C[i] = C[i - 1] + C[i] * r;
		C[0] *= r;
	}
	return C;
}

int main()
{
	int n;
	cin >> n;
	vector<long long> P = PolynomialExpansion(n);
	for (int i = P.size() - 1; i > 0; --i)
		cout << P[i] << "x^" << i + 1 << '+';
	cout << P[0] << "x^1";
}
