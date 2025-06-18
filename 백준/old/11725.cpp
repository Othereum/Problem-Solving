#include <bits/stdc++.h>
using namespace std;

struct Node {
    int parent = -1;
    vector<int> children;

    void setParent(int i) {
        parent = i;
        erase(children, i);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<Node> tree(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        // 아직은 누가 부모인지 구분이 안되므로 일단 양쪽 모두 children에 추가
        tree[a-1].children.push_back(b-1);
        tree[b-1].children.push_back(a-1);
    }

    // BFS: 루트 노드에서부터 트리 구조 파악하기
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (int j : tree[i].children) {
            tree[j].setParent(i);
            q.push(j);
        }
    }

    // 각 노드의 부모 노드 번호 출력
    for (int i = 1; i < n; i++) {
        cout << (tree[i].parent + 1) << '\n';
    }
}
