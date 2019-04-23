// https://www.hackerrank.com/challenges/bon-appetit

#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int sum{};
    for (int i{}; i<n; ++i)
    {
        int a;
        cin >> a;
        if (i != k)
            sum += a;
    }
    int b;
    cin >> b;
    const int c{ b - sum / 2 };
    if (c == 0)
    {
        cout << "Bon Appetit";
    }
    else
    {
        cout << c;
    }
}