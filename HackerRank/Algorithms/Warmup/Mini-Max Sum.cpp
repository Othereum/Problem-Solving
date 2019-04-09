// https://www.hackerrank.com/challenges/mini-max-sum

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int n = 5;
constexpr int SumN = 4;

int main()
{
    array<int, n> arr;
    for (int& i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    long long min=0, max=0;
    for (int i=0; i<SumN; ++i)
        min += arr[i];
    for (int i=n-SumN; i<n; ++i)
        max += arr[i];
    cout << min << ' ' << max;
}
