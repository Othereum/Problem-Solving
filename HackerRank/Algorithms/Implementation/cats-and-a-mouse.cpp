// https://www.hackerrank.com/challenges/cats-and-a-mouse
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int q;
    cin >> q;
    for (auto i{ 0 }; i < q; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        const auto a{ abs(x - z) }, b{ abs(y - z) };
        cout << (a < b ? "Cat A\n" : a > b ? "Cat B\n" : "Mouse C\n");
    }
}