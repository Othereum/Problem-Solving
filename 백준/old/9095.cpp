#include <bits/stdc++.h>
using namespace std;

int CACHE[10];
int solve(int n)
{
    if (n < 0) return 0;
    if (n <= 1) return 1;

    int& ret = CACHE[n-1];
    if (ret != -1) return ret;
    
    return ret = solve(n-1) + solve(n-2) + solve(n-3);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(CACHE, -1, sizeof(CACHE));

    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++)
    {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}
