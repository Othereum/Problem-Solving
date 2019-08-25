#include <array>
#include <iostream>
using namespace std;

array<uint8_t, 1000> arr;

unsigned fair_rations(const unsigned size)
{
	unsigned loaves = 0;
	for (unsigned i = 0; i < size-1; ++i)
	{
		if (arr[i] % 2)
		{
			++arr[i];
			++arr[i+1];
			loaves += 2;
		}
	}
	return loaves;
}

int main()
{
	unsigned n;
	cin >> n;
	
	unsigned num_odd = 0;
	for (unsigned i = 0; i < n; ++i)
	{
		unsigned b;
		cin >> b;
		arr[i] = b;
		if (b % 2) ++num_odd;
	}

	if (num_odd % 2) cout << "NO";
	else cout << fair_rations(n);
}
