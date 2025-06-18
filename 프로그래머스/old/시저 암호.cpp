#include <string>
using namespace std;

string solution(string s, const int n)
{
	for (auto& c : s)
	{
		if ('A' <= c && c <= 'Z')
			c = 'A' + (c - 'A' + n) % 26;

		else if ('a' <= c && c <= 'z')
			c = 'a' + (c - 'a' + n) % 26;
	}
	return s;
}
