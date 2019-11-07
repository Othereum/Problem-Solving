// https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	static constexpr size_t num_best_songs_per_genre{ 2 };

	const auto size{ genres.size() };

	// 장르별 총 플레이 횟수
	unordered_map<string, int> total_plays;
	for (size_t i{}; i < size; ++i)
		total_plays[genres[i]] += plays[i];

	// 노래 장르 정렬 함수. 총 플레이 횟수가 많은 순으로 정렬.
	auto genre_cmp = [&total_plays](const string & lhs, const string & rhs)
	{ return total_plays[lhs] > total_plays[rhs]; };

	// 노래의 인덱스와 그 플레이 횟수를 저장하는 pair 타입
	using pair_idx_plays = pair<size_t, int>;

	// pair_idx_plays 정렬 함수 객체. 플레이 횟수 내림차순. 같으면 인덱스 낮은 것이 앞에 옴.
	struct plays_cmp
	{
		bool operator()(const pair_idx_plays& lhs, const pair_idx_plays& rhs)
		{
			return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second > rhs.second;
		};
	};

	// 노래들을 정렬된 상태로 유지하는 multiset 타입
	using plays_multiset = multiset<pair_idx_plays, plays_cmp>;

	// 장르별 노래들을 정렬된 상태로 유지하는 map 타입
	using genre_plays_map = map<string, plays_multiset, decltype(genre_cmp)>;

	// 장르별 노래
	genre_plays_map genre_plays(genre_cmp);

	// 장르 생성
	for (const auto& genre : genres)
		genre_plays[genre];

	// 장르에 노래<인덱스, 플레이횟수> 추가
	for (size_t i{}; i < size; ++i)
		genre_plays.at(genres[i]).emplace(i, plays[i]);


	vector<int> answer;

	// 추가 과정에서 자동으로 정렬되기 때문에 따로 정렬해줄 필요가 없음
	for (const auto& playlist : genre_plays)
	{
		// 각 장르별로 가장 앞의 노래 num_best_songs_per_genre개를 가져옴
		auto it = playlist.second.cbegin();
		for (size_t i{}; i < num_best_songs_per_genre && it != playlist.second.cend(); ++i)
		{
			answer.push_back(it->first);
			++it;
		}
	}

	return answer;
}
