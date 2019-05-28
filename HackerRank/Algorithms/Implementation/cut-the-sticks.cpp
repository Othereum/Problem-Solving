#include <algorithm>
#include <vector>
using namespace std;
vector<int> cutTheSticks(vector<int> arr) {
    sort(arr.begin(), arr.end());
    auto a{arr[0]}, cnt{0};
    auto left{arr.size()};
    vector<int> ret;
    for (auto x : arr) {
        if (a == x)
            ++cnt;
        else {
            ret.push_back(left);
            left -= cnt;
            cnt = 1;
            a = x;
        }
    }
    ret.push_back(cnt);
    return ret;
}
