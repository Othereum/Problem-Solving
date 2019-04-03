#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int tt{}; tt < t; ++tt)
    {
        int len;
        cin >> len;
        vector<int> q(len);
        for (int i{}; i < len; ++i)
            cin >> q[i];
        int ans{};
        for (int i{len-1}; i > 0; --i)
        {
            int idx{i};
            while (q[idx] != i + 1)
                --idx;
            if (i - idx > 2)
            {
                cout << "Too chaotic\n";
                ans = -1;
                break;
            }
            while (i != idx)
            {
                swap(q[idx], q[idx+1]);
                ++idx;
                ++ans;
            }
        }
        if (ans != -1)
            cout << ans << '\n';
    }
}