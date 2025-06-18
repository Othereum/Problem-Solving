#include <bits/stdc++.h>
using namespace std;

// 네트워크 그래프
// network[i]: i+1번 PC에 연결되어 있는 다른 PC의 목록
vector<vector<int>> network;

// 감염된 PC 집합
set<int> infected;

void propagate(int i)
{
    if (infected.contains(i))
        return;

    infected.insert(i);

    for (int j : network[i])
        propagate(j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numPC, numLink;
    cin >> numPC >> numLink;

    network.resize(numPC);

    for (int i = 0; i < numLink; i++)
    {
        int a, b;
        cin >> a >> b;

        // PC 연결 (양방향)
        network[a-1].push_back(b-1);
        network[b-1].push_back(a-1);
    }

    // 1번 PC부터 탐색 시작
    propagate(0);

    // 1번 컴퓨터를 통해 감염되는 PC 수를 구해야 하므로 1번 PC는 제외
    int victims = infected.size() - 1;
    
    cout << victims;
}
