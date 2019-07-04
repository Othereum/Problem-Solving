#include <iostream>
#include <vector>

using namespace std;

void insertionSort2(vector<int>& arr) {
	for (size_t i = 0; i < arr.size() - 1; ++i) {
		if (arr[i] > arr[i + 1])
			for (size_t j = i + 1; arr[j - 1] > arr[j]; --j)
				swap(arr[j - 1], arr[j]);
		for (int n : arr) cout << n << ' '; cout << '\n';
	}
}

template <typename T> T get() { T t; cin >> t; return t; }
template <typename T> vector<T> get(size_t sz) {
	vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

int main()
{
	auto arr = get<int>(get<size_t>());
	insertionSort2(arr);
}
