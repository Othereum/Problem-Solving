#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    return min(s.size(), nums.size() / 2);
}
