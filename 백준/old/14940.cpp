#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int height, width;
    cin >> height >> width;

    vector<vector<int>> distances(height);
    for (auto& row : distances) {
        row.resize(width, -1);
    }

    queue<pair<int, int>> q;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int n;
            cin >> n;
            switch (n) {
                case 0:
                    distances[y][x] = 0; 
                    break;
                case 2: [[unlikely]]
                    distances[y][x] = 0;
                    q.emplace(x, y);
                    break;
            }
        }
    }

    auto visit = [&](int x, int y, int d) {
        if (x < 0 || x >= width) return;
        if (y < 0 || y >= height) return;
        if (distances[y][x] != -1) return;
        distances[y][x] = d;
        q.emplace(x, y);
    };

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int d = distances[y][x] + 1;
        visit(x-1, y, d);
        visit(x+1, y, d);
        visit(x, y-1, d);
        visit(x, y+1, d);
    }

    for (auto& row : distances) {
        for (int d : row) {
            cout << d << ' ';
        }
        cout << '\n';
    }
}
