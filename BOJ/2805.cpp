#include <bits/stdc++.h>
using namespace std;

int TREE[1000000];
int TREE_COUNT;
int TREE_REQUIRED;

/**
 * 절단기를 주어진 높이 h로 설정했을 때
 * 필요한 만큼의 나무를 얻을 수 있는지 확인
 */
bool isEnough(int h)
{
    // 각 나무의 높이는 최대 1,000,000,000 이므로
    // 전체 합을 구하려면 int64_t 필요
    int64_t sum = 0;

    for (int i = 0; i < TREE_COUNT; i++)
    {
        sum += std::max(0, TREE[i] - h);
    }

    return sum >= TREE_REQUIRED;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> TREE_COUNT >> TREE_REQUIRED;

    int max = 0;
    for (int i = 0; i < TREE_COUNT; i++)
    {
        cin >> TREE[i];
        max = std::max(max, TREE[i]);
    }

    // <매개변수 탐색> 조건을 만족하는 최대값 찾기
    // -> 필요한 만큼의 나무를 얻을 수 있는 절단기의 최대 높이 찾기

    // <초기값>
    // 절단기의 가능한 최소 높이는 0 (모든 나무를 벤다)
    // 절단기의 최대 높이는 가장 높은 나무의 높이가 된다
    int low = 0, high = max;

    int answer = 0;

    // 더 이상 탐색할 범위(시도해볼 절단기 높이)가 남아있지 않을 때까지 반복
    while (low <= high)
    {
        // 중앙값 시도
        int mid = (low + high) / 2;

        // 조건을 만족한다면 (나무가 충분함)
        if (isEnough(mid))
        {
            // 정답(절단기 최대 높이) 후보 갱신
            answer = mid;

            // 탐색 범위 좁히기 (더 높여본다)
            low = mid + 1;
        }
        // 절단기가 너무 높음 (나무가 부족함)
        else
        {
            // 탐색 범위 좁히기 (더 낮춰본다)
            high = mid - 1;
        }
    }

    // 시간 복잡도: O(N log N)
    // 한 번의 탐색마다 탐색할 범위가 절반씩 줄어들므로 log N
    // 한 번의 탐색마다 조건을 만족하는지 확인하기 위해 모든 나무를 확인하므로 N

    cout << answer;
}
