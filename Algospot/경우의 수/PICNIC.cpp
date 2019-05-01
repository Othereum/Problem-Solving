// https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;

// fp[i]: i번 사람의 친구 목록
// left: 아직 짝을 찾지 못한 아이들 목록
int CountPair(const vector<set<int>>& fp, set<int>& left)
{
	// 기저 사례: 두 명 남음
	if (left.size() == 2)
	{
		auto first = left.cbegin();
		const auto a = *first, b = *(++first);
		// 두 명이 서로 친구여서 짝을 만들 수 있으면 1, 아니면 0을 반환
		return fp[a].find(b) != fp[a].cend();
	}

	auto cnt = 0;

	const auto first = *left.begin();
	left.erase(first);

	// first번 아이의 친구들 각각에 대하여
	for (auto c : fp[first])
	{
		// 아직 짝을 찾지 못했다면
		if (left.find(c) != left.end())
		{
			// first번 아이와 짝을 지어주고
			left.erase(c);

			// 나머지 아이들에 대해서 짝을 지어준다
			cnt += CountPair(fp, left);

			left.insert(c);
		}
	}

	left.insert(first);

	return cnt;
}

int main()
{
	int c;
	cin >> c;
	for (auto t = 0; t < c; ++t)
	{
		// 아이 n 명, 친구 m 쌍
		int n, m;
		cin >> n >> m;
		vector<set<int>> fp(n);
		for (auto i = 0; i < m; ++i)
		{
			// a, b는 서로 친구
			int a, b;
			cin >> a >> b;

			// 중복으로 세는 경우를 방지하기 위해 순서를 오름차순으로 강제
			if (a > b) swap(a, b);
			fp[a].insert(b);
		}

		set<int> people;
		for (auto i = 0; i < n; ++i)
			people.insert(i);

		cout << CountPair(fp, people) << '\n';
	}
}
