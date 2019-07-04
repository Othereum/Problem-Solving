#include <iostream>
#include <vector>

using namespace std;

template <typename T> T get() { T t; cin >> t; return t; }

int main()
{
	vector<vector<string>> v;
	const auto n = get<unsigned>();
	for (auto i = n/2; i < n; ++i)
	{
		const auto idx = get<unsigned>();
		if (idx >= v.size()) v.resize(idx + 1);
		get<string>();
		v[idx].emplace_back("-");
	}
	for (auto i = n/2; i < n; ++i)
	{
		const auto idx = get<unsigned>();
		if (idx >= v.size()) v.resize(idx + 1);
		v[idx].emplace_back(get<string>());
	}
	for (auto& s : v)
		for (auto& ss : s)
			cout << ss << ' ';
}
