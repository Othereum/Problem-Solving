#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    size_t n; cin >> n;
    vector<string> arr(n);
    for (string& s : arr)
        cin >> s;
    sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
        return a.size() == b.size() ? a < b : a.size() < b.size();
    });
    for (string& s : arr)
        cout << s << '\n';
}
