/*
주어진 자연수 N에 대해 3가지 연산 (/5, /2, -1)이 가능하다.
N을 1로 만들기 위해 필요한 최소 연산 횟수를 출력하라.
*/

#include <iostream>
using namespace std;

int n;
int cnt;

void MakeCloserToOne()
{
	const int orig{ n };
	if (n % 5 == 0) n /= 5;
	else if (n % 2 == 0) n /= 2;
	else n--;
	if (orig != n) ++cnt;
}

int main()
{
	cin >> n;
	while (n > 1) MakeCloserToOne();
	cout << cnt;
}
