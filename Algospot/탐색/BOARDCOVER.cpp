// https://algospot.com/judge/problem/read/BOARDCOVER

#include <iostream>
#include <vector>
#include <array>
using namespace std;

class BoardCover
{
public:
	BoardCover()
	{
		GetInput();
		cout << Solution() << '\n';
	}

private:
	// 게임 보드판. false면 비어있고, true면 채워져 있는 것
	vector<vector<bool>> board;

	// 4개의 각 블록은 중심점에 대한 x, y의 offset을 나타냄
	// 중심을 포함하면서 "상단 좌측"부터 채우도록 함
	// "상단부터, 그리고 좌측"이 중요. 이거때문에 삽질했다
	// 중복으로 세지 않기 위해서 순서를 상단->하단, 좌측->우측으로 강제하기 때문에
	// 기준점보다 앞쪽에 있는 칸에는 절대 빈칸이 없기 때문이다
	static constexpr array<array<array<int, 2>, 3>, 4> blocks{ { {{{0,0},{0,1},{1,0}}}, {{{0,0},{0,1},{1,1}}}, {{{0,0},{1,0},{1,1}}}, {{{0,0},{1,-1},{1,0}}} } };

	int Solution()
	{
		const auto white = NumWhite();
		// 블록은 3칸을 차지하기 때문에 빈칸이 3의 배수가 아니면 절대 채울 수 없다
		if (white % 3 != 0)
			return 0;
		// 빈칸이 없으면 이미 채워져 있는 것으로 간주하여 하나의 경우로 본다
		if (white == 0)
			return 1;
		return NumWays();
	}

	int NumWays()
	{
		auto y = -1, x = y;
		// 빈칸을 "상단 좌측"부터 찾아본다
		GetFirstValid(y, x);
		// 기저 사례: 빈칸이 없다면 블럭 채우기 성공, 하나의 경우가 됨
		if (y == -1) return 1;
		
		auto cnt = 0;
		// 4개의 블럭 각각에 대하여
		for (auto i = 0; i < 4; ++i)
		{
			// 여기에 이 블럭을 놓을 수 있다면
			if (CanCover(y, x, i))
			{
				// 블럭을 놓고
				SetBlock(y, x, i, true);
				// 남은 공간에 블럭을 놓는 경우의 수를 더함
				cnt += NumWays();
				// 블럭을 뺀다
				SetBlock(y, x, i, false);
			}
		}
		return cnt;
	}

	void SetBlock(int y, int x, int block, bool bSet)
	{
		for (auto& bd : blocks[block])
			board[y + bd[0]][x + bd[1]] = bSet;
	}

	bool CanCover(int y, int x, int block) const
	{
		for (auto& bd : blocks[block])
			if (!CanCover(y + bd[0], x + bd[1]))
				return false;
		return true;
	}

	bool CanCover(int y, int x) const
	{
		return IsInRange(y, x) && !board[y][x];
	}

	bool IsInRange(int y, int x) const
	{
		return y >= 0 && y < board.size() && x >= 0 && x < board[y].size();
	}

	int NumWhite() const
	{
		auto num = 0;
		for (auto& row : board)
			for (auto cell : row)
				if (!cell) ++num;
		return num;
	}

	void GetFirstValid(int& y, int& x) const
	{
		for (auto i = 0; i < board.size(); ++i)
		{
			for (auto j = 0; j < board[i].size(); ++j)
			{
				if (!board[i][j])
				{
					y = i;
					x = j;
					return;
				}
			}
		}
	}

	void GetInput()
	{
		int h, w;
		cin >> h >> w;
		board.reserve(h);
		for (auto i = 0; i < h; ++i)
		{
			vector<bool> row;
			row.reserve(w);
			for (auto j = 0; j < w; ++j)
			{
				char c;
				cin >> c;
				row.push_back(c == '#');
			}
			board.emplace_back(move(row));
		}
	}
};

// C++11은 static constexpr 멤버에 대한 정의가 필요하다
// https://stackoverflow.com/questions/8016780/undefined-reference-to-static-constexpr-char
constexpr array<array<array<int, 2>, 3>, 4> BoardCover::blocks;

int main()
{
	const auto C = [] {int C; cin >> C; return C; }();
	for (auto _ = 0; _ < C; ++_)
	{
		BoardCover{};
	}
}