#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr)
{
	const int p = arr[0];
	size_t storeIdx = 0;
	for (size_t i = 1; i < arr.size(); ++i)
		if (arr[i] < p) swap(arr[++storeIdx], arr[i]);
	swap(arr[storeIdx], arr[0]);
}

template <typename T> T get() { T t; cin >> t; return t; }
template <typename T> vector<T> get(size_t sz) {
	vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

int main()
{
	auto arr = get<int>(get<size_t>());
	quickSort(arr);
	for (int n : arr) cout << n << ' ';
}
