#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;
    for (int x : arr) if (x % divisor == 0) answer.push_back(x);
    if (answer.size() == 0) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}
