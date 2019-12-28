#include <utility>

using namespace std;

long long solution(int a, int b)
{
    if (a > b) swap(a, b);
    auto answer = 0ll;
    for (auto i=a; i<=b; ++i) answer += i;
    return answer;
}
