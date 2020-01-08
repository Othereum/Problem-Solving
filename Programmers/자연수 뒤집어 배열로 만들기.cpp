#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    const auto s = to_string(n);
    answer.reserve(s.size());
    for (auto it=s.rbegin(); it!=s.rend(); ++it)
        answer.push_back(*it - '0');
    return answer;
}