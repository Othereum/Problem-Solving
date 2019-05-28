#include <unordered_map>
#include <vector>
using namespace std;
int equalizeArray(vector<int> arr)
{
    unordered_map<int, int> n;
    auto m{arr[0]};
    for (auto a : arr)
    {
        ++n[a];
        if (n[m] < n[a]) m = a;
    }
    return arr.size() - n[m];
}
