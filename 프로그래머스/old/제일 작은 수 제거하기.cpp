#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    auto min = begin(arr);
    for (auto it = next(min); it != end(arr); ++it)
        if (*it < *min) min = it;
    arr.erase(min);
    if (arr.empty()) arr.push_back(-1);
    return arr;
}