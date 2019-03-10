#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int len;
    cin >> len;
    vector<int> arr(len);
    for (int i{}; i < len; ++i)
        cin >> arr[i];
    int numSwap{};
    for (int i{len-1}; i > 0; --i)
    {
        int idx{i};
        while (arr[idx] != i + 1) --idx;
        if (idx != i)
        {
            swap(arr[idx], arr[i]);
            ++numSwap;
        }
    }
    cout << numSwap;
}