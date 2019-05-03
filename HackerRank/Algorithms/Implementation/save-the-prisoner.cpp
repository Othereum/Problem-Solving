// https://www.hackerrank.com/challenges/save-the-prisoner

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (auto i{ 0 }; i < t; ++i)
	{
		int prisoners, sweets, begin;
		cin >> prisoners >> sweets >> begin;
		cout << ((sweets - 1) % prisoners + begin - 1) % prisoners + 1 << '\n';
	}
}
