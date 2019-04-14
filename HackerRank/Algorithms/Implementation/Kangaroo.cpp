// https://www.hackerrank.com/challenges/kangaroo

#include <iostream>
using namespace std;

int main()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    while (x1 != x2)
    {
        const int d = abs(x1 - x2);
        x1 += v1;
        x2 += v2;
        if (d <= abs(x1 - x2))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
