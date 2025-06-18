#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
    auto s = to_string(n);
    sort(s.rbegin(), s.rend());
    return stoll(s);
}
