#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    constexpr int MAX = 100001;
    vector<bool> visited(MAX);
    vector<int> elapsed(MAX);
    queue<int> q;
    q.push(n);
    visited[n] = true;

    auto visit = [&](int x, int t)
    {
        if (x < 0 || x >= MAX) return;
        if (visited[x]) return;

        visited[x] = true;
        elapsed[x] = t;
        q.push(x);
    };

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int t = elapsed[x];

        if (x == k) return t;

        visit(x-1, t+1);
        visit(x+1, t+1);
        visit(2*x, t+1);
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
}
