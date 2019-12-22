#include <array>
#include <numeric>
#include <string>

using namespace std;

string solution(const int a, const int b)
{
	static const array<int, 11> m{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	const auto d = std::accumulate(m.begin(), m.begin() + (a - 1), 0) + (b-1);

	static const array<string, 7> w{"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
	return w[d%7];
}
