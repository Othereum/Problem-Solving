// https://algospot.com/judge/problem/read/CLOCKSYNC

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

template<class T>
T Next() { T t; cin >> t; return t; }

constexpr auto ClockNum = 16;
using ClockArr = array<int, ClockNum>;

constexpr auto SwitchesNum = 10;
const array<vector<int>, SwitchesNum> Switches{{ {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13} }};

void ClockSync(ClockArr& Clocks, int& OutMinCnt, const int SwitchIdx, const int SwitchPressCnt)
{
	if (SwitchIdx < SwitchesNum)
	{
		// 스위치 한 번도 안누름
		ClockSync(Clocks, OutMinCnt, SwitchIdx + 1, SwitchPressCnt);

		// 스위치를 3번 누름
		for (auto i = 1; i <= 3; ++i)
		{
			// 누르기
			for (auto ClockIdx : Switches[SwitchIdx])
			{
				Clocks[ClockIdx] += 3;
				if (Clocks[ClockIdx] > 12) Clocks[ClockIdx] = 3;
			}
			// 한 번씩 누를 때마다 나머지 스위치들에 대해 조합 탐색
			ClockSync(Clocks, OutMinCnt, SwitchIdx + 1, SwitchPressCnt + i);
		}

		// 3번 눌렀던 스위치 복구
		for (auto i = 1; i <= 3; ++i)
		{
			for (auto ClockIdx : Switches[SwitchIdx])
			{
				Clocks[ClockIdx] -= 3;
				if (Clocks[ClockIdx] < 3) Clocks[ClockIdx] = 12;
			}
		}
	}
	// 기저사례: 모든 스위치를 탐색함 (하나의 '스위치 누르기 조합' 완성)
	else 
		// 모든 시계가 12시라면 현재 조합의 스위치 누른 횟수와 최소값을 비교하여 저장
		if (SwitchPressCnt < OutMinCnt && all_of(Clocks.begin(), Clocks.end(), [](int i) {return i == 12; }))
			OutMinCnt = SwitchPressCnt;
}

int ClockSync(ClockArr& Clocks)
{
	static constexpr auto Max = numeric_limits<int>::max();
	auto MinCnt = Max;
	ClockSync(Clocks, MinCnt, 0, 0);
	return MinCnt == Max ? -1 : MinCnt;
}

int main()
{
	for (auto c = Next<int>(); c > 0; --c)
	{
		ClockArr Clocks;
		for (auto& Clock : Clocks)
			cin >> Clock;
		cout << ClockSync(Clocks) << '\n';
	}
}
