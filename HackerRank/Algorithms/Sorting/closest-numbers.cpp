#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> T get() { T t; cin >> t; return t; }

template <typename T> vector<T> get(size_t sz)
{
	vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (const T& t : v) os << t << ' ';
	return os;
}

int main()
{
	auto arr = get<int>(get<size_t>());
	sort(arr.begin(), arr.end());
	auto min_diff = numeric_limits<int>::max();
	vector<int> ans;
	for (size_t i = 1; i < arr.size(); ++i)
	{
		const auto diff = arr[i] - arr[i-1];
		if (diff < min_diff)
		{
			ans.clear();
			min_diff = diff;
		}
		if (diff == min_diff)
		{
			ans.push_back(arr[i-1]);
			ans.push_back(arr[i]);
		}
	}
	cout << ans;
}
