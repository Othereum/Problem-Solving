#include <forward_list>
#include <iostream>
#include <vector>
using namespace std;

int beautifulTriplets(int d, const vector<int>& arr)
{
	int cnt = 0;
	forward_list<vector<int>> triplets;
	for (int a : arr)
	{
		for (auto prev_it = triplets.before_begin();;)
		{
			const auto it = next(prev_it);
			if (it == triplets.end())
			{
				triplets.emplace_after(prev_it, initializer_list<int>{ a });
				break;
			}

			if (a - it->back() == d)
			{
				if (it->size() == 2)
				{
					++cnt;
					triplets.erase_after(prev_it);
					continue;
				}
				it->push_back(a);
			}

			++prev_it;
		}
	}
	return cnt;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> arr(n);
	for (int& a : arr)
		cin >> a;
	cout << beautifulTriplets(d, arr);
}
