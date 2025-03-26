#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if (n < 0) return 0;
    if (n <= 1) return 1;
    return solve(n-1) + solve(n-2) + solve(n-3);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++)
    {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}
