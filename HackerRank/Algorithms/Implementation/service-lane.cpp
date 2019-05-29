#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	vector<int> width(n);
	for (int& w : width)
		cin >> w;
	for (int _ = 0; _ < t; ++_)
	{
		int i, j;
		cin >> i >> j;
		const auto it = width.begin();
		cout << *min_element(it + i, it + j + 1) << '\n';
	}
}
