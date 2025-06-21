#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> vec(N);
    for (vector<int>& v : vec) {
        v.resize(N);
        cin >> v[0];
        for (int i = 1; i < N; i++) {
            cin >> v[i];
            v[i] += v[i-1];
        }
    }

    for (int m = 0; m < M; m++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int sum = 0;
        for (int row = x1-1; row < x2; row++) {
            int s = vec[row][y2-1];
            if (y1 >= 2) {
                s -= vec[row][y1-2];
            }
            sum += s;
        }
        cout << sum << '\n';
    }
}
