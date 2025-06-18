#include <string>

using namespace std;

string solution(const string s)
{
	const auto len = s.length();
	const auto odd = len % 2;
    return s.substr(len / 2 - (1 - odd), 2 - odd);
}
