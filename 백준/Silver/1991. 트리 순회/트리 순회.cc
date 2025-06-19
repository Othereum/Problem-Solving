#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
};

class Graph {
    vector<Node> graph;

public:
    void read() {
        int n;
        cin >> n;

        graph.resize(n);
        for (int i = 0; i < n; i++) {
            string x, l, r;
            cin >> x >> l >> r;
            Node& node = graph[x[0] - 'A'];
            node.l = l[0] - 'A';
            node.r = r[0] - 'A';
        }
    }

    void preorder() {
        preorder(0);
        cout << '\n';
    }

    void inorder() {
        inorder(0);
        cout << '\n';
    }

    void postorder() {
        postorder(0);
        cout << '\n';
    }

private:
    void visit(int x) {
        cout << (char)(x + 'A');
    }

    void preorder(int i) {
        if (i < 0) return;
        visit(i);
        preorder(graph[i].l);
        preorder(graph[i].r);
    }

    void inorder(int i) {
        if (i < 0) return;
        inorder(graph[i].l);
        visit(i);
        inorder(graph[i].r);
    }

    void postorder(int i) {
        if (i < 0) return;
        postorder(graph[i].l);
        postorder(graph[i].r);
        visit(i);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph graph;
    graph.read();
    graph.preorder();
    graph.inorder();
    graph.postorder();
}
