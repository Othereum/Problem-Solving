#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> numbers(n);
    for (int i = 0; i < n; i++) {
        numbers[i].resize(i+1);
        for (int& x : numbers[i]) {
            cin >> x;
        }
    }

    auto get = [&](int i, int j) {
        if (i >= 0 && i < n) {
            if (j >= 0 && j <= i) {
                return numbers[i][j];
            }
        }
        return 0;
    };

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            numbers[i][j] += max(get(i-1, j-1), get(i-1, j));
            answer = max(answer, numbers[i][j]);
        }
    }

    cout << answer;
}
