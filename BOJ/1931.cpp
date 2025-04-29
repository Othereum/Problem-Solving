#include <bits/stdc++.h>
using namespace std;

using I = pair<int, int>;
int solve(vector<I> meetings) {
    ranges::sort(meetings, [](const I& a, const I& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    int answer = 0;
    int last = 0;
    for (auto [s, e] : meetings) {
        if (s >= last) {
            answer++;
            last = e;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<I> meetings(n);
    for (auto& [s, e] : meetings) {
        cin >> s >> e;
    }
    
    cout << solve(move(meetings));
}
