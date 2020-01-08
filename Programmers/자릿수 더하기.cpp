#include <string>

using namespace std;
int solution(int n)
{
    auto sum = 0;
    for (char c : to_string(n))
        sum += c - '0';
    return sum;
}