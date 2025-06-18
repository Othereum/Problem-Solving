#include <bits/stdc++.h>
using namespace std;

class Solver {
    vector<int> s;
    int last;

    void recurse(int first, int length) {
        if (length <= 0) {
            print();
            return;
        }

        for (int i = first; i <= last; i++) {
            s.push_back(i);
            recurse(i + 1, length - 1);
            s.pop_back();
        }
    }

    void print() {
        for (int x : s) {
            cout << x << ' ';
        }
        cout << '\n';
    }

public:
    void solve(int n, int m) {
        s.clear();
        last = n;
        recurse(1, m);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    Solver solver;
    solver.solve(n, m);
}
