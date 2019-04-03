// https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <iostream>
#include <vector>

using namespace std;
using uint64 = unsigned long long;

int main()
{
    int Len, Cmd;
    cin >> Len >> Cmd;
    vector<int> arr(Len+1);
    for (int c = 0; c < Cmd; ++c)
    {
        int StartIdx, EndIdx, AddVal;
        cin >> StartIdx >> EndIdx >> AddVal;

        arr[StartIdx-1] += AddVal;
        arr[EndIdx] -= AddVal;
    }
    uint64 max = 0;
    uint64 cur = 0;
    for (int n : arr)
    {
        cur += n;
        if (cur > max) max = cur;
    }
    cout << max;
}
