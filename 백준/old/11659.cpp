#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, numRange;
    cin >> num >> numRange;

    vector<int> numbers(num);
    for (int& n : numbers)
        cin >> n;

    vector<int> partialSum(num);
    partial_sum(numbers.begin(), numbers.end(), partialSum.begin());

    auto getSum = [&](int idx) {
        return idx < 0 ? 0 : partialSum[idx];
    };

    for (int i = 0; i < numRange; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << getSum(b-1) - getSum(a-2) << '\n';
    }
}
