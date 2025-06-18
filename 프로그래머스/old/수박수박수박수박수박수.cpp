#include <string>

using namespace std;

string solution(const int n)
{
    static const string arr[]{"수", "박"};
    string answer;
    answer.reserve(n*arr[0].size());
    for (auto i=0; i<n; ++i)
        answer += arr[i%2];
    return answer;
}
