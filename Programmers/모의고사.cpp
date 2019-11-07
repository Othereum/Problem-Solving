// https://programmers.co.kr/learn/courses/30/lessons/42840

#include <vector>
#include <algorithm>

using namespace std;

class picker
{
public:
    picker(const initializer_list<int> pattern)
		:pattern_{pattern}
    {
    }

	picker& operator++() { idx_ = (idx_+1) % pattern_.size(); return *this; }
    int get() const { return pattern_[idx_]; }

private:
	vector<int> pattern_;
	size_t idx_ = 0;
};

vector<int> solution(const vector<int> answers)
{
    vector<picker> pattern
    {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
	
	vector<int> scores(pattern.size());
    
    for (const auto a : answers)
    {
	    for (size_t i = 0; i < pattern.size(); ++i)
	    {
		    if (pattern[i].get() == a) ++scores[i];
	    	++pattern[i];
	    }
    }

	vector<int> ans;
	auto max = 0;
	for (size_t i = 0; i < scores.size(); ++i)
	{
		if (scores[i] > max)
		{
			max = scores[i];
			ans.clear();
			ans.push_back(i + 1);
		}
		else if (scores[i] == max)
		{
			ans.push_back(i + 1);
		}
	}

	return ans;
}
