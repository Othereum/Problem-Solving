#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    void Push(int x)
    {
        vec.push_back(x);
        
        int i = vec.size() - 1;
        while (i > 0 && vec[i] < vec[Parent(i)])
        {
            swap(vec[i], vec[Parent(i)]);
            i = Parent(i);
        }
    }

    int Pop()
    {
        if (vec.empty()) return 0;

        const int ret = vec[0];
        vec[0] = vec.back();
        vec.pop_back();

        int i = 0;
        while (true)
        {
            int right = (i+1) * 2;
            int left = right - 1;

            if (left >= vec.size())
                break; // 자식 없음, 끝 도달
    
            int target = right >= vec.size() ? left // 자식이 하나만 있음
                : vec[left] < vec[right] ? left : right; // 둘 중 작은 자식 선택

            if (vec[i] <= vec[target])
                break; // 제자리 도달

            // 자식이 더 작은 경우 swap
            swap(vec[i], vec[target]);
            i = target;
        }

        return ret;
    }

private:
    int Parent(int i) { return (i + 1) / 2 - 1; }
    vector<int> vec;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numOp;
    cin >> numOp;

    Heap heap;
    for (int i = 0; i < numOp; i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            cout << heap.Pop() << '\n';
        }
        else
        {
            heap.Push(x);
        }
    }
}
