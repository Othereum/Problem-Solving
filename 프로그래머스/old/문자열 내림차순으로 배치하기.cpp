#include <algorithm>
#include <string>

using namespace std;

string solution(string s)
{
    sort(s.begin(), s.end(), [](char a, char b){return a>b;});
    return s;
}
