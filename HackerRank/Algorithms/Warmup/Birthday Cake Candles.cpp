// https://www.hackerrank.com/challenges/birthday-cake-candles

#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int max=0, cnt=0;
    for (int i=0;i<n;++i) {
        int h; cin >> h;
        if (h > max) {
            max = h; cnt = 1;
        }
        else if (h == max) ++cnt;
    }
    cout << cnt;
}
