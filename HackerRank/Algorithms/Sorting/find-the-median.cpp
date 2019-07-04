#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> T get() { T t; cin >> t; return t; }

template <typename T> vector<T> get(size_t sz)
{
    vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

int main()
{
	auto arr = get<short>(get<size_t>());
	sort(arr.begin(), arr.end());
	cout << arr[arr.size() / 2];
}
