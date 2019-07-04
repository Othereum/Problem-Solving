#include <iostream>
#include <vector>

using namespace std;

size_t runningTime(vector<int>& arr) {
	size_t shiftCnt = 0;
	for (size_t i = 0; i < arr.size() - 1; ++i) {
		if (arr[i] > arr[i + 1])
			for (size_t j = i + 1; j > 0 && arr[j - 1] > arr[j]; --j) {
				swap(arr[j - 1], arr[j]);
				++shiftCnt;
			}
	}
	return shiftCnt;
}

template <typename T> T get() { T t; cin >> t; return t; }
template <typename T> vector<T> get(size_t sz) {
	vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

int main()
{
	auto arr = get<int>(get<size_t>());
	cout << runningTime(arr);
}
