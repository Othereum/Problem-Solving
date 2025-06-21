#include <bits/stdc++.h>
using namespace std;

int arr[1025][1025];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    for (int m = 0; m < M; m++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1]) << '\n';
    }
}
