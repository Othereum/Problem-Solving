#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <span>
using namespace std;

int SumOfTimes(span<int> times)
{
	int sum = 0, acc = 0;
	for (int time : times)
		sum += acc += time;
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> P(N);
	for (int& p : P)
		cin >> p;

	ranges::sort(P);
	cout << SumOfTimes(P);
}
