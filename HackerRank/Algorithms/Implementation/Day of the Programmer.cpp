// https://www.hackerrank.com/challenges/day-of-the-programmer

#include <iostream>
using namespace std;

bool IsLeapYear(int y)
{
	bool bIsLeapYear{ y % 4 == 0 };
	if (y > 1918) bIsLeapYear = bIsLeapYear && y % 100 != 0 || y % 400 == 0;
	return bIsLeapYear;
}

int main()
{
	int y;
	cin >> y;
	if (y == 1918)
	{
		cout << "26.09.1918";
	}
	else
	{
		cout << '1' << (IsLeapYear(y) ? '2' : '3') << ".09." << y;
	}
}
