// https://www.hackerrank.com/challenges/circular-array-rotation

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> arr(n);
	for (auto i{ 0 }; i < n; ++i)
	{
		int a;
		cin >> a;
		arr[(i + k) % n] = a;
	}
	for (auto i{ 0 }; i < q; ++i)
	{
		int m;
		cin >> m;
		cout << arr[m] << '\n';
	}
}