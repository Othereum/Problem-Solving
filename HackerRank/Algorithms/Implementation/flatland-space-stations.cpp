#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

size_t flatlandSpaceStations(size_t n, vector<size_t> c)
{
	if (n == c.size()) return 0;
	sort(c.begin(), c.end());
	priority_queue<size_t> pq;
	pq.push(c.front());
	for (size_t i = 1; i < c.size(); ++i)
		pq.push((c[i] - c[i - 1]) / 2);
	pq.push(n - c.back() - 1);
	return pq.top();
}

int main()
{
	size_t n, m;
	cin >> n >> m;
	vector<size_t> c; c.reserve(m);
	while (m--) {
		size_t b; cin >> b;
		c.push_back(b);
	}
	cout << flatlandSpaceStations(n, move(c));
}
