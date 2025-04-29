#include <bits/stdc++.h>
using namespace std;

int solve(int n, int r, int c) {
    if (n <= 0) return 0;
    if (n == 1) return 2*r + c;

    int h = 1 << (n - 1);
    int q = 0;
    if (r >= h) q += 2;
    if (c >= h) q += 1;

    int quater = 1 << (2*n - 2);
    return q * quater + solve(n-1, r%h, c%h);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r, c;
    cin >> n >> r >> c;
    cout << solve(n, r, c);
}
