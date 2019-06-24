#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

set<int> missingNumbers(const vector<int>& arr, const vector<int>& brr)
{
	set<int> ret;
	unordered_map<int, unsigned> a, b;
	for (int n : arr) ++a[n];
	for (int n : brr) ++b[n];
	for (auto& p : b)
		if (a.find(p.first) == a.end() || a[p.first] < p.second)
			ret.insert(p.first);
	return ret;
}

int main()
{
	size_t n; int b;
	cin >> n;
	vector<int> arr; arr.reserve(n);
	while (n--) { cin >> b; arr.push_back(b); }
	cin >> n;
	vector<int> brr; brr.reserve(n);
	while (n--) { cin >> b; brr.push_back(b); }
	for (int a : missingNumbers(arr, brr))
		cout << a << ' ';
}
