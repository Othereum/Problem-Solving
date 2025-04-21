#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numNode, numLink;
    cin >> numNode >> numLink;

    vector<vector<int>> graph(numNode);

    for (int i = 0; i < numLink; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    auto range = views::iota(0, numNode);
    unordered_set<int> s(range.begin(), range.end());
    deque<int> q;
    int answer = 0;

    while (!s.empty())
    {
        auto it = s.begin();
        q.push_back(*it);
        s.erase(it);
        while (!q.empty())
        {
            int i = q.front();
            q.pop_front();

            for (int j : graph[i])
            {
                if (s.erase(j))
                {
                    q.push_back(j);
                }
            }
        }

        answer++;
    }

    cout << answer;
}
