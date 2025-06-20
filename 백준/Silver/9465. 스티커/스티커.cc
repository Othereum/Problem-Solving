#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    vector<int> stickers[2];
    auto get = [&](int i, int j) {
        if (0 <= j && j < stickers[i].size()) {
            return stickers[i][j];
        }
        return 0;
    };

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        for (vector<int>& vec : stickers) {
            vec.resize(n);
            for (int& n : vec) {
                cin >> n;
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            stickers[0][i] += max(get(1, i-1), get(1, i-2));
            stickers[1][i] += max(get(0, i-1), get(0, i-2));
            answer = max(answer, max(stickers[0][i], stickers[1][i]));
        }
        cout << answer << '\n';
    }
}
