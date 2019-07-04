#include <iostream>
#include <vector>

using namespace std;

template <typename T> T get() { T t; cin >> t; return t; }

template <typename T> vector<T> get(size_t sz)
{
    vector<T> arr; arr.reserve(sz); while (sz--) arr.push_back(get<T>()); return arr;
}

unsigned cnt_arr[100];

int main()
{
    const auto sz = get<size_t>();
    const auto arr = get<unsigned short>(sz);
    for (int n : arr) ++cnt_arr[n];
    for (size_t i = 0; i < 100; ++i)
        for (unsigned j = 0; j < cnt_arr[i]; ++j)
            cout << i << ' ';
}
