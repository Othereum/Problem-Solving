#include <bits/stdc++.h>
using namespace std;

vector<bool> FIELD;
vector<bool> SEARCHED;
int WIDTH, HEIGHT;

int Index(int x, int y)
{
    return x + y*WIDTH;
}

void Search(int x, int y)
{
    if (x < 0 || x >= WIDTH) return;
    if (y < 0 || y >= HEIGHT) return;

    int idx = Index(x, y);
    if (SEARCHED[idx]) return;

    if (FIELD[idx])
    {
        SEARCHED[idx] = true;
        Search(x - 1, y);
        Search(x + 1, y);
        Search(x, y - 1);
        Search(x, y + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTC;
    cin >> numTC;
    for (int i = 0; i < numTC; i++)
    {
        int numPos;
        cin >> WIDTH >> HEIGHT >> numPos;

        FIELD.resize(WIDTH*HEIGHT);
        SEARCHED.resize(WIDTH*HEIGHT);
        
        for (int j = 0; j < numPos; j++)
        {
            int x, y;
            cin >> x >> y;
            FIELD[Index(x, y)] = true;
        }

        int answer = 0;
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (FIELD[Index(x, y)] && !SEARCHED[Index(x, y)])
                {
                    answer++;
                    Search(x, y);
                }
            }
        }

        cout << answer << '\n';

        FIELD.clear();
        SEARCHED.clear();
    }
}
