#include <list>
#include <vector>
using namespace std;

struct truck
{
	explicit truck(const int w) :w{w}, d{0} {}
	int w;
	int d;
};

int solution(const int bridge_length, const int weight, const vector<int> truck_weights)
{
	list<truck> cross;
	auto cur_w = 0, time = 0;
	auto idx = 0u;
	for (;;++time)
	{
		if (cross.empty() && idx >= truck_weights.size()) break;
		
		if (!cross.empty())
		{
			for (auto& t : cross)
				++t.d;

			auto& front_truck = cross.front();
			if (front_truck.d >= bridge_length)
			{
				cur_w -= front_truck.w;
				cross.pop_front();
			}
		}

		if (idx < truck_weights.size() && cur_w + truck_weights[idx] <= weight)
		{
			cross.emplace_back(truck_weights[idx]);
			cur_w += truck_weights[idx];
			++idx;
		}
	}
	
	return time;
}
