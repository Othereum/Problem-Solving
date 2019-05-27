#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	static int Solve(const vector<int>& Fences) { return Solve(Fences, 0, Fences.size() - 1); }

private:
	static int Solve(const vector<int>& Fences, const int Low, const int High)
	{
		// 기저 사례: 배열 크기가 1임
		if (Low == High) return Fences[Low];

		// 최대 크기는 (1)왼쪽에 있거나, (2)오른쪽에 있거나, (3)그 사이에 걸쳐 있을 수도 있다.
		const auto Mid = (High + Low) / 2;

		// (3) 구하기
		auto Height = min(Fences[Mid], Fences[Mid + 1]);
		auto Max = Height * 2;
		for (auto l = Mid - 1, r = Mid + 2; Low <= l || r <= High;)
		{
			Height = min(Height, Fences[Low <= l && (High < r || Fences[l] > Fences[r]) ? l-- : r++]);
			Max = max(Max, Height * (r - l - 1));
		}

		// (1), (2), (3)의 경우 중 최댓값을 반환
		return max({ Solve(Fences, Low, Mid), Solve(Fences, Mid + 1, High), Max });
	}
};

template <class T>
T Next() { T t; cin >> t; return t; }

template <class T>
vector<T> ReadArr()
{
	vector<T> arr;
	const auto n = Next<int>();
	for (auto i = 0; i < n; ++i)
		arr.emplace_back(Next<T>());
	return arr;
}

template <class Fn>
void IterateTestcases(Fn&& Func)
{
	for (auto i = Next<int>(); i > 0; --i)
		Func();
}

int main()
{
	IterateTestcases([] {cout << Solution::Solve(ReadArr<int>()) << '\n'; });
}
