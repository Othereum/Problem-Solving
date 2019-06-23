#include <iostream>
#include <vector>

using namespace std;

class jumpgame
{
public:
	jumpgame(vector<vector<uint8_t>>&& v)
		:board{ move(v) }, cache(board.size(), vector<int8_t>(board.size(), -1))
	{
	}

	bool operator()() const
	{
		return sub(0, 0);
	}

private:
	bool sub(size_t y, size_t x) const
	{
		const size_t size = board.size();
		if (y + 1 == size && x + 1 == size) return true;
		if (y >= size || x >= size) return false;
		return cache[y][x] != -1 ? cache[y][x] : (cache[y][x] = sub(y, x + board[y][x]) || sub(y + board[y][x], x));
	}

	vector<vector<uint8_t>> board;
	mutable vector<vector<int8_t>> cache;
};

int main()
{
	int C; cin >> C;
	while (C--)
	{
		size_t n; cin >> n;
		vector<vector<uint8_t>> board(n);
		for (auto& row : board)
		{
			row.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				unsigned a; cin >> a;
				row.push_back(a);
			}
		}
		cout << (jumpgame{ move(board) }() ? "YES" : "NO") << '\n';
	}
}
