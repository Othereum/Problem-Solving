// https://www.hackerrank.com/challenges/apple-and-orange

#include <iostream>
using namespace std;

int main()
{
    int s, t, a, b, m, n;
    cin >> s >> t >> a >> b >> m >> n;
    int apples{};
    for (int i{}; i<m; ++i) {
        int j; cin >> j; j += a;
        if (s <= j && j <= t) ++apples;
    }
    cout << apples << '\n';
    int oranges{};
    for (int i{}; i<n; ++i) {
        int j; cin >> j; j += b;
        if (s <= j && j <= t) ++oranges;
    }
    cout << oranges << '\n';
}