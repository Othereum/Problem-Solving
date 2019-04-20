// https://www.hackerrank.com/challenges/migratory-birds
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[5]{};
	for (int i = 0; i < n; ++i)
	{
		int b;
		cin >> b;
		++arr[b-1];
	}
	int max = 0;
	for (int i = 0; i < 5; ++i)
		if (arr[i] > arr[max])
			max = i;
	cout << max + 1;
}
