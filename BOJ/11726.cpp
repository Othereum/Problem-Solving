#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1001;

int solve(int n)
{
    if (n < 0) return 1;

    static int f[MAX]{1, 1};
    static int i = 2;
    if (n < i) return f[n];

    for (; i <= n; i++)
        f[i] = (f[i-1] + f[i-2]) % 10007;

    return f[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << solve(n);
}
