// https://www.hackerrank.com/challenges/strange-advertising

#include <iostream>
using namespace std;

int ViralAdvertising(const int NumDays)
{
	auto Liked{ 2 };
	auto Cumulative{ 2 };
	for (auto Days{ 1 }; Days < NumDays; ++Days)
	{
		Liked = Liked * 3 / 2;
		Cumulative += Liked;
	}
	return Cumulative;
}

int main()
{
	int n;
	cin >> n;
	cout << ViralAdvertising(n);
}
