// https://www.hackerrank.com/challenges/time-conversion

#include <iostream>
#include <string>
using namespace std;

string ToStr(int n)
{
    string s = to_string(n);
    if (s.size() == 1)
        return '0' + s;
    return s;
}

int main()
{
    int h, m, s;
    char b;
    cin >> h;
    cin >> b;
    cin >> m;
    cin >> b;
    cin >> s;
    cin >> b;
    if (b == 'A' && h == 12) h = 0;
    else if (b == 'P' && h != 12) h += 12;
    cout << ToStr(h) << ':' << ToStr(m) << ':' << ToStr(s);
}