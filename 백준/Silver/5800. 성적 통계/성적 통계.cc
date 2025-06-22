#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    vector<int> scores;
    for (int k = 0; k < K; k++) {
        int N; cin >> N;
        scores.resize(N);
        for (int& score : scores) {
            cin >> score;
        }
        sort(scores.begin(), scores.end());

        int min = scores[0];
        int max = scores[0];
        int gap = 0;
        for (int i = 1; i < N; i++) {
            min = std::min(min, scores[i]);
            max = std::max(max, scores[i]);
            gap = std::max(gap, scores[i] - scores[i-1]);
        }

        cout << "Class " << (k+1) << '\n';
        cout << "Max " << max << ", Min " << min << ", Largest gap " << gap << '\n';
    }
}
