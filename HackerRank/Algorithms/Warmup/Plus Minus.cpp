// https://www.hackerrank.com/challenges/plus-minus/problem

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int pp=0, nn=0, zz=0;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        if (a > 0) ++pp;
        else if (a < 0) ++nn;
        else ++zz;
    }
    cout << (double)pp / n << '\n'
        << (double)nn / n << '\n'
        << (double)zz / n << '\n';
}