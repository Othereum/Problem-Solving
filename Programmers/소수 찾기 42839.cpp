// https://programmers.co.kr/learn/courses/30/lessons/42839
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

bool IsPrime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	
	for (auto i = 2; i*i <= n; ++i)
		if (n % i == 0) return false;

	return true;
}

void solution(string numbers, unordered_set<int>& set)
{
	if (numbers.empty()) return;
    std::sort(numbers.begin(), numbers.end());
    
    do {
    	if (numbers[0] == '0') continue;
    	const auto num = stoi(numbers);
        if (IsPrime(num)) set.insert(num);
    } while (std::next_permutation(numbers.begin(), numbers.end()));

	const auto size = numbers.size();
	for (size_t i = 0; i < size; ++i)
        solution(numbers.substr(0, i) + numbers.substr(i+1, size-i-1), set);
}

int solution(string numbers)
{
	unordered_set<int> set;
	solution(std::move(numbers), set);
    return set.size();
}
