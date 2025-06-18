#include <string>
using namespace std;

bool solution(const string s)
{
	unsigned counts[26]{};
	for (auto c : s) ++counts[tolower(c)-'a'];
	return counts['p'-'a'] == counts['y'-'a'];
}
