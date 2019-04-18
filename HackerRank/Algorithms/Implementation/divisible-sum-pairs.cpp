// https://www.hackerrank.com/challenges/divisible-sum-pairs
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int& a : ar)
        cin >> a;
    int cnt = 0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<i; ++j)
            if ((ar[i] + ar[j]) % k == 0)
                ++cnt;
    cout << cnt;
}