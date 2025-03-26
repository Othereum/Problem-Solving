#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    n = abs(n);
    if (n == 0) return 0;

    static int fib[40]{1, 1};
    static int i = 2;
    for (; i < n; i++)
    {
        fib[i] = fib[i-2] + fib[i-1];
    }
    return fib[n-1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        cout << fibonacci(N-1) << ' ' << fibonacci(N) << '\n';
    }
}
