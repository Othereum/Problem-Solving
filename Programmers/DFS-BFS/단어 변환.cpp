// https://programmers.co.kr/learn/courses/30/lessons/43163

/*
words 내의 단어가 정점
단어 사이에 변환이 가능하면 간선을 연결
너비 우선 탐색으로 begin부터 최단 경로 탐색
target을 찾으면 경로를 역추적하여 변환 횟수 측정
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool IsConvertible(const string& a, const string& b);

int solution(string begin, string target, vector<string> words)
{
	// begin은 words 안에 없으므로 가상의 인덱스를 설정
	static constexpr auto begin_idx{ static_cast<size_t>(-1) };

	const auto size{ words.size() };

	// 너비 우선 탐색을 위한 탐색 queue
	queue<size_t> search_queue;

	// 정점 간선
	unordered_map<size_t, size_t> parents;

	// begin에 간선 잇기
	for (size_t i{}; i < size; ++i)
	{
		if (IsConvertible(begin, words[i]))
		{
			search_queue.push(i);
			parents[i] = begin_idx;
		}
	}

	while (!search_queue.empty())
	{
		const auto idx{ search_queue.front() };
		search_queue.pop();

		if (target == words[idx])
		{
			auto p{ idx };
			auto cnt{ 0 };

			// 변환된 경로를 역추적하여 횟수 계산
			while (p != begin_idx)
			{
				p = parents[p];
				++cnt;
			}

			return cnt;
		}
		else
		{
			// 정점을 탐색하여 새 간선을 잇고 탐색 queue에 추가
			for (size_t i{}; i < size; ++i)
			{
				if (parents.find(i) == parents.end() && IsConvertible(words[idx], words[i]))
				{
					search_queue.push(i);
					parents[i] = idx;
				}
			}
		}
	}
	// 변환 실패
	return 0;
}

// 두 문자열간에 다른 문자가 한 개만 있어야 true
bool IsConvertible(const string& a, const string& b)
{
	auto bDiffFound{ false };
	const auto size{ a.size() };
	for (size_t i{}; i < size; ++i)
	{
		if (a[i] != b[i])
		{
			if (bDiffFound)
				return false;
			else
				bDiffFound = true;
		}
	}
	return bDiffFound;
}
