#include <iostream>
#include <vector>

using namespace std;

void insertionSort1(vector<int>& arr) {
	for (size_t i = arr.size() - 1; i && arr[i - 1] > arr[i]; --i) {
		int tmp = arr[i];
		arr[i] = arr[i - 1];
		for (int n : arr) cout << n << ' ';
		cout << '\n';
		arr[i - 1] = tmp;
	}
}

template <typename T> T get() { T t; cin >> t; return t; }
template <typename T> vector<T> get(size_t sz) {
	vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

int main()
{
	auto arr = get<int>(get<size_t>());
	insertionSort1(arr);
	for (int n : arr) cout << n << ' ';
}
