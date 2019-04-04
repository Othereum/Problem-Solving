// https://www.hackerrank.com/challenges/compare-the-triplets/problem

#include <iostream>
using namespace std;

int main()
{
    int a[3], b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    int a_ = 0, b_ = 0;
    if (a[0] > b[0]) ++a_;
    else if (a[0] < b[0]) ++b_;
    if (a[1] > b[1]) ++a_;
    else if (a[1] < b[1]) ++b_;
    if (a[2] > b[2]) ++a_;
    else if (a[2] < b[2]) ++b_;
    cout << a_ << ' ' << b_;
}
