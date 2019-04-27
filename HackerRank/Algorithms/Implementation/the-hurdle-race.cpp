// https://www.hackerrank.com/challenges/the-hurdle-race
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    auto max{0};
    for (auto i{0}; i<n; ++i)
    {
        int h;
        cin >> h;
        if (h > max) max = h;
    }
    auto d{max - k};
    cout << (d > 0 ? d : 0);
}
