#include <bits/stdc++.h>
using namespace std;

int64_t reverse(int64_t n) {
    int64_t result = 0;
    while (n > 0) {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;

    vector<int64_t> nums(count);
    for (int64_t& n : nums) {
        cin >> n;
        n = reverse(n);
    }

    ranges::sort(nums);
    for (int64_t n : nums) {
        cout << n << '\n';
    }
}
