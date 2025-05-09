#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<array<int, 3>> houses(n);
    for (auto& [r, g, b] : houses) {
        cin >> r >> g >> b;
    }

    for (int i = 1; i < n; i++) {
        auto& [r, g, b] = houses[i];
        auto& [pr, pg, pb] = houses[i-1];
        r += min(pg, pb);
        g += min(pr, pb);
        b += min(pr, pg);
    }

    cout << ranges::min(houses[n - 1]);
}
