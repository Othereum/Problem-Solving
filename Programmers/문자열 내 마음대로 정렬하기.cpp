#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> solution(vector<string> strings, const int n)
{
	std::sort(strings.begin(), strings.end(), [n](const string& a, const string& b)
	{
		return a[n] != b[n] ? a[n] < b[n] : a < b;
	});
	
	return strings;
}
