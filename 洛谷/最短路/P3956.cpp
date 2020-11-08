#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
const int maxm = 105;
int G[maxm][maxm];
int gold[maxm][maxm];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
void input()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = c + 1;
    }
}
struct HeapNode
{
    int x;
    int y;
    int last_c;
    int gold = 0;
    void print()
    {
        printf("(%d,%d)=%c %d\n", x, y, "RY"[last_c - 1], gold);
    }
};
bool OK(int x, int y)
{
    return x <= M && x >= 1 && y <= M && y >= 1;
}
int bfs()
{
    int res = 0x3f3f3f3f;
    memset(gold, 0x3f, sizeof(gold));
    queue<HeapNode> q;
    q.push({1, 1, G[1][1], 0});
    gold[1][1] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        int ox=cur.x,oy=cur.y;
        int last_color = cur.last_c;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (!OK(nx, ny))
                continue;
            if (G[cur.x][cur.y] == 0 && G[nx][ny] == 0)
                continue;
            int &ngold = gold[nx][ny];
            int cur_gold = cur.gold;
            if (last_color == G[nx][ny])
            {
                if (ngold <= cur_gold)
                    continue;
                q.push({nx, ny, last_color, cur_gold});
                ngold = cur_gold;
            }
            else if (last_color + G[nx][ny] == 3)
            {
                if (ngold <= cur_gold + 1)
                    continue;
                q.push({nx, ny, G[nx][ny], cur_gold + 1});
                ngold = cur_gold + 1;
            }
            else if (G[nx][ny] == 0)
            {
                if (ngold <= cur_gold + 2)
                    continue;
                ngold = cur_gold + 2;
                if (last_color == 1)
                {
                    q.push({nx, ny, 1, cur_gold + 2});
                    q.push({nx, ny, 2, cur_gold + 3});
                }
                else
                {
                    q.push({nx, ny, 1, cur_gold + 3});
                    q.push({nx, ny, 2, cur_gold + 2});
                }
            }
        }
    }
    if (gold[M][M] == 0x3f3f3f3f)
        return -1;
    return gold[M][M];
}
int main()
{
    input();
    std::cout << bfs() << std::endl;
    return 0;
}