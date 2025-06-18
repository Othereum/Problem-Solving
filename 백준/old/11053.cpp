#include <bits/stdc++.h>
using namespace std;

int solve(span<int> numbers) {
    int longest = 0;
    vector<int> lengths(numbers.size());
    for (size_t i = 0; i < numbers.size(); i++) {
        int maxlen = 0;
        for (size_t j = 0; j < i; j++) {
            if (numbers[j] < numbers[i]) {
                maxlen = max(maxlen, lengths[j]);
            }
        }
        lengths[i] = maxlen + 1;
        longest = max(longest, lengths[i]);
    }
    return longest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int& x : numbers) {
        cin >> x;
    }

    cout << solve(numbers);
}
