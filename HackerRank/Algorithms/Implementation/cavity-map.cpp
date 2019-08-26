#include <iostream>
using namespace std;

char map[101][101];

template <class T>
T get() { T t; cin >> t; return t; }

int main()
{
	const auto n = get<unsigned>();
	for (auto i = 0u; i < n; ++i)
		cin >> map[i];

	for (auto i = 1u; i < n-1; ++i)
	{
		for (auto j = 1u; j < n-1; ++j)
		{
			if (map[i][j] > map[i-1][j] &&
				map[i][j] > map[i+1][j] &&
				map[i][j] > map[i][j-1] &&
				map[i][j] > map[i][j+1])
			{
				map[i][j] = 'X';
			}
		}
	}

	for (auto i = 0u; i < n; ++i)
		cout << map[i] << '\n';
}
