// https://www.hackerrank.com/challenges/grading

#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        int s; cin >> s;
        if (s >= 38) {
            const int m = s % 5;
            if (m >= 3) s += 5 - m;
        }
        cout << s << '\n';
    }
}