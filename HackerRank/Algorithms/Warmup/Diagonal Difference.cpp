// https://www.hackerrank.com/challenges/diagonal-difference/problem

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s1{}, s2{};
    for (int i{}; i<n; ++i)
        for (int j{}; j<n; ++j){
            int a;
            cin >> a;
            if (i==j) s1+=a;
            if (i+j==n-1) s2+=a;
        }
    cout << abs(s1-s2);
}
