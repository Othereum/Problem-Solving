#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t a, b, c;
    cin >> a >> b >> c;

    a %= c;

    int64_t d = 1;
    while (b > 1) {
        if (b % 2 == 0) {
            a *= a;
            a %= c;
            b /= 2;
        } else {
            d *= a;
            d %= c;
            b--;
        }
    }

    int64_t answer = a * d % c;
    cout << answer;
}
