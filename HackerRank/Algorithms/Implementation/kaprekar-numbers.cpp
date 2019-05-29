#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int64_t> kaprekarNumbers(int64_t p, int64_t q)
{
	vector<int64_t> ret;
	for (int64_t n = p; n <= q; ++n)
	{
		const int64_t d = to_string(n).size();
		const string n2s = to_string(n * n);
		const int64_t rs = n2s.size() - d;
		const int64_t lh = rs == 0 ? 0 : stoll(n2s.substr(0, rs));
		const int64_t rh = stoll(n2s.substr(rs, d));
		if (lh + rh == n) ret.push_back(n);
	}
	return ret;
}

int main()
{
	int64_t p, q;
	cin >> p >> q;
	vector<int64_t> kn = kaprekarNumbers(p, q);
	if (kn.empty())
		cout << "INVALID RANGE";
	else for (int64_t n : kn)
		cout << n << ' ';
}
