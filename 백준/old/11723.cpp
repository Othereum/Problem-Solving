#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int ReadInt()
{
	int x;
	cin >> x;
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	bool S[20]{};
	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "add")
		{
			S[ReadInt() - 1] = true;
		}
		else if (cmd == "remove")
		{
			S[ReadInt() - 1] = false;
		}
		else if (cmd == "check")
		{
			cout << S[ReadInt() - 1] << '\n';
		}
		else if (cmd == "toggle")
		{
			int i = ReadInt() - 1;
			S[i] = !S[i];
		}
		else if (cmd == "all")
		{
			memset(S, true, 20);
		}
		else if (cmd == "empty")
		{
			memset(S, false, 20);
		}
	}
}
