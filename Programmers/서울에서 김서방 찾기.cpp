#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(const vector<string> seoul)
{
	string answer = "김서방은 ";
	answer += std::to_string(find_if(seoul.begin(), seoul.end(), [](const string& s){return s == "Kim";}) - seoul.begin());
	answer += "에 있다";
	return answer;
}
