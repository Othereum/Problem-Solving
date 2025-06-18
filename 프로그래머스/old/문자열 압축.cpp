#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class string_view
{
public:
	string_view(const char* const str, const size_t cnt)
		:str_{str}, len_{cnt}
	{
	}

	bool operator==(const string_view& o) const
	{
		if (len_ != o.len_) return false;
		if (str_ == o.str_) return true;

		for (size_t i = 0; i < len_; ++i)
			if (str_[i] != o.str_[i])
				return false;

		return true;
	}

	friend string& operator+=(string& s, const string_view& r)
	{
		s.append(r.str_, r.len_);
		return s;
	}

private:
	const char* const str_;
	const size_t len_;
};

int solution(const string s)
{
	auto min = numeric_limits<size_t>::max();
	
	vector<string_view> split;
	string compressed;
	
	for (size_t i = 1; i <= s.size(); ++i)
	{
		for (size_t j = 0; j < s.size(); j += i)
			split.emplace_back(s.data() + j, std::min(i, s.size() - j));
		
		auto n = 1;
		for (size_t j = 1; j < split.size(); ++j)
		{
			if (split[j-1] == split[j]) ++n;
			else
			{
				if (n > 1)
				{
					compressed += to_string(n);
					n = 1;
				}
				compressed += split[j-1];
			}
		}
		if (n > 1) compressed += to_string(n);
		compressed += split.back();

		if (compressed.size() < min) min = compressed.size();

		split.clear();
		compressed.clear();
	}

	return min;
}
