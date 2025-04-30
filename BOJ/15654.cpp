#include <bits/stdc++.h>
using namespace std;

class Solver {
    vector<int> numbers_;
    vector<size_t> s_;

    void recurse(int length) {
        if (length <= 0) {
            print();
            return;
        }

        for (size_t i = 0; i < numbers_.size(); i++) {
            if (ranges::find(s_, i) != s_.end()) {
                continue;
            }
            s_.push_back(i);
            recurse(length - 1);
            s_.pop_back();
        }
    }

    void print() {
        for (size_t i : s_) {
            cout << numbers_[i] << ' ';
        }
        cout << '\n';
    }

public:
    void solve(vector<int> numbers, int length) {
        ranges::sort(numbers);
        numbers_ = move(numbers);
        s_.clear();
        recurse(length);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<int> numbers(n);
    for (int& x : numbers) {
        cin >> x;
    }

    Solver solver;
    solver.solve(move(numbers), m);
}
