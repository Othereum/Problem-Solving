#include <cmath>

using namespace std;

long long solution(long long n)
{
    auto x = sqrt(n);
    auto lx = static_cast<long long>(x);
    if (x == lx) return (lx+1)*(lx+1);
    return -1;
}