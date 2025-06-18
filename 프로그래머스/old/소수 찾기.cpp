#include <vector>
#include <algorithm>

using namespace std;

int solution(const int n)
{
	// not_prime[i]가 false이면 i+1은 소수
	vector<bool> not_prime(n);
	not_prime[0] = true;
	
	for (auto i=1; i<n; ++i)
	{
		if (!not_prime[i])
		{
			for (auto j=(i+1)*2-1; j<n; j+=i+1)
			{
				not_prime[j] = true;
			}
		}
	}

	return count(not_prime.begin(), not_prime.end(), false);
}
