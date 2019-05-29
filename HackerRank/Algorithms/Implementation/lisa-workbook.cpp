#include <iostream>
#include <vector>
using namespace std;

int workbook(const vector<int>& arr, const int k)
{
	const int n = arr.size();
	int cnt = 0;
	for (int p = 0, i = 0; i < n;)
	{
		for (int a = 1; a <= arr[i]; ++a)
		{
			if (k == 1 || a % k == 1) ++p;
			if (a == p) ++cnt;
		}
		++i;
	}
	return cnt;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int& a : arr)
		cin >> a;
	cout << workbook(arr, k);
}
