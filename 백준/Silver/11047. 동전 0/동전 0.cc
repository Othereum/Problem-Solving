#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int& coin : coins) {
        cin >> coin;
    }

    int count = 0;
    for (int i = n; i > 0; i--) {
        while (k >= coins[i-1]) {
            k -= coins[i-1];
            count++;
        }
    }

    cout << count;
}
