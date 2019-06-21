#include <string>
#include <iostream>
#include <regex>
#include <set>

using namespace std;

int main()
{
	unsigned C; cin >> C;
	while (C--)
	{
		string b;
		cin >> b;
		for (size_t i = 0; i < b.size(); ++i)
		{
			if (b[i] == '?') b[i] = '.';
			else if (b[i] == '*') b.replace(i++, 1, ".*");
		}
		regex wildcard{ move(b) };
		unsigned N; cin >> N;
		multiset<string> matched;
		while (N--)
		{
			cin >> b;
			if (regex_match(b, wildcard))
				matched.insert(move(b));
		}
		for (auto& s : matched)
			cout << s << '\n';
	}
}
