// https://www.oncoder.com/developer/score-detail/SyTKZzp3E

#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution
{
public:
	int solution(vector<string> list, const int nZ, const int nO)
	{
		// 0과 1의 개수에 대한 데이터로 변환
		list01.resize(list.size());
		for (auto i{ 0 }; i < list.size(); ++i)
			for (auto c : list[i]) ++list01[i][c - '0'];

		n0 = nZ;
		n1 = nO;

		// 가능한 모든 조합을 탐색하여 최대값 구함
		search();

		return Max;
	}

private:
	vector<array<int, 2>> list01;
	int n0, n1;
	mutable int Max{}, Idx{}, Sum0{}, Sum1{}, CurCnt{};

	void search() const
	{
		if (Idx >= list01.size())
		{
			if (Sum0 <= n0 && Sum1 <= n1 && Max < CurCnt)
				Max = CurCnt;
			return;
		}

		++Idx;
		search();
		--Idx;
		Sum0 += list01[Idx][0];
		Sum1 += list01[Idx][1];
		++CurCnt;
		++Idx;
		search();
		--Idx;
		--CurCnt;
		Sum0 -= list01[Idx][0];
		Sum1 -= list01[Idx][1];
	}
};
