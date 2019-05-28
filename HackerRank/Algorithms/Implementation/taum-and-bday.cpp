#include <iostream>
using namespace std;

long long taumBday(long long b, long long w, long long bc, long long wc, long long z)
{
	if (abs(bc - wc) > z)
	{
		if (bc < wc)
			return bc * (b + w) + w * z;
		return wc * (b + w) + b * z;
	}
	return b * bc + w * wc;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int b, w, bc, wc, z;
		cin >> b >> w >> bc >> wc >> z;
		cout << taumBday(b, w, bc, wc, z) << '\n';
	}
}
