#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> byIdx(n);
    unordered_map<string, int> byName;
    for (int i = 0; i < n; i++) {
        cin >> byIdx[i];
        byName[byIdx[i]] = i;
    }

    string prompt;
    for (int i = 0; i < m; i++) {
        cin >> prompt;
        if (isdigit(prompt[0])) {
            cout << byIdx[stoi(prompt)-1] << '\n';
        } else {
            cout << byName[prompt]+1 << '\n';
        }
    }
}
