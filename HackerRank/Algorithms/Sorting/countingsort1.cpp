#include <iostream>
#include <vector>
using namespace std;
template <typename T> T get() { T t; cin >> t; return t; }
template <typename T> vector<T> get(size_t sz) {
	vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}
unsigned cnt_arr[100];
int main()
{
	const auto sz = get<size_t>();
	const auto arr = get<unsigned short>(sz);
	for (int n : arr) ++cnt_arr[n];
	for (auto n : cnt_arr) cout << n << ' ';
}
