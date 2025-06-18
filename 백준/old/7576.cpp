#include <bits/stdc++.h>
using namespace std;

int solve(const vector<vector<int8_t>>& tomatos) {
    constexpr int UNREACHED = -1;
    constexpr int NO_TOMATO = -2;

    const int rows = (int)tomatos.size();
    const int cols = (int)tomatos[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> distances(rows);
    for (auto& row : distances) {
        row.resize(cols, UNREACHED);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            switch (tomatos[i][j]) {
                case 1:
                    distances[i][j] = 0;
                    q.emplace(i, j);
                    break;
                case -1:
                    distances[i][j] = NO_TOMATO;
                    break;
            }
        }
    }

    auto visit = [&](int i, int j, int d) {
        if (i < 0 || i >= rows) return;
        if (j < 0 || j >= cols) return;
        if (distances[i][j] == UNREACHED) {
            distances[i][j] = d;
            q.emplace(i, j);
        }
    };

    int d = 0;
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        d = distances[i][j];
        visit(i-1, j, d+1);
        visit(i+1, j, d+1);
        visit(i, j-1, d+1);
        visit(i, j+1, d+1);
    }

    for (const auto& row : distances) {
        for (int d : row) {
            if (d == UNREACHED) {
                return -1;
            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cols, rows;
    cin >> cols >> rows;

    vector<vector<int8_t>> tomatos(rows);
    for (auto& row : tomatos) {
        row.resize(cols);
        for (int8_t& cell : row) {
            int n; cin >> n;
            cell = (int8_t)n;
        }
    }
    
    cout << solve(tomatos);
}
