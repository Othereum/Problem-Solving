#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> passwords;
    for (int i = 0; i < n; i++) {
        string url, password;
        cin >> url >> password;
        passwords.emplace(move(url), move(password));
    }

    string prompt;
    for (int i = 0; i < m; i++) {
        cin >> prompt;
        cout << passwords.at(prompt) << '\n';
    }
}
