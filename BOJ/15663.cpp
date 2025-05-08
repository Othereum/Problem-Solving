#include <bits/stdc++.h>
using namespace std;

class Solver {
    vector<int> numbers_;
    vector<size_t> s_;
    unordered_set<string> set_;

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
        ostringstream ss;
        for (size_t i : s_) {
            ss << numbers_[i] << ' ';
        }
        auto [it, inserted] = set_.insert(ss.str());
        if (inserted) {
            cout << *it << '\n';
        }
    }

public:
    void solve(vector<int> numbers, int length) {
        ranges::sort(numbers);
        numbers_ = move(numbers);
        s_.clear();
        set_.clear();
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
