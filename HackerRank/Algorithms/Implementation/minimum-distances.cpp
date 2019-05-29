#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int minimumDistances(const vector<int>& a)
{
	unordered_map<int, int> numIdx;
	int minD = numeric_limits<int>::max();
	const int size = a.size();
	for (int i = 0; i < size; ++i)
	{
		if (!numIdx.emplace(a[i], i).second)
		{
			minD = min(minD, i - numIdx[a[i]]);
			numIdx[a[i]] = i;
		}
	}
	return minD == numeric_limits<int>::max() ? -1 : minD;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int& a : arr)
		cin >> a;
	cout << minimumDistances(arr);
}
