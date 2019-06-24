#include <iostream>
#include <vector>

using namespace std;

bool balancedSums(const vector<int>& arr)
{
	int lsum = 0, rsum = 0;
	for (size_t i = 1; i < arr.size(); ++i) rsum += arr[i];
	if (lsum == rsum) return true;
	for (size_t i = 1; i < arr.size(); ++i)
	{
		lsum += arr[i - 1];
		rsum -= arr[i];
		if (lsum == rsum) return true;
	}
	return false;
}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		size_t n; cin >> n;
		vector<int> arr; arr.reserve(n);
		while (n--) { int b; cin >> b; arr.push_back(b); }
		cout << (balancedSums(arr) ? "YES" : "NO") << '\n';
	}
}
