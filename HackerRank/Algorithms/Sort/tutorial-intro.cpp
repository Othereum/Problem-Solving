#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> T get() { T t; cin >> t; return t; }
template <typename T> vector<T> get(size_t sz) {
	vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

int main()
{
	const auto v = get<int>();
	const auto arr = get<int>(get<size_t>());
	cout << find(arr.begin(), arr.end(), v) - arr.begin();
}
