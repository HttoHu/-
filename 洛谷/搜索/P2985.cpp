#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 50005;
int vis[305][305];
int vvis[305][305];
int dx[] = {1, 0, -1, 0,0};
int dy[] = {0, -1, 0, 1,0};
void input()
{
    memset(vis, -1, sizeof(vis));
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for(int i=0;i<5;i++)
        {
            int nx=a+dx[i],ny=b+dy[i];
            if(nx>=0 &&ny>=0)
                if (vis[nx][ny] == -1 || vis[nx][ny] > c)
                    vis[nx][ny] = c;
        }
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         printf("%-5d", vis[i][j]);
    //     printf("\n");
    // }
}
struct Bassie
{
    int x, y, t;
};
// 1 ok still alive
// 0 damn
// -1 success to leave.
int check(int x, int y, int t)
{
    if (x < 0 || y < 0)
        return 0;
    if (vis[x][y] == -1)
        return -1;
    if (t >= vis[x][y] || vvis[x][y])
        return 0;
    return 1;
}
int bfs()
{
    queue<Bassie> q;
    if (vis[0][0] == 0)
        return -1;
    else if (vis[0][0] == -1)
        return 0;
    q.push({0, 0, 0});
    vvis[0][0]=1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i], ny = cur.y + dy[i], nt = cur.t + 1;
            int res = check(nx, ny, nt);
            if (res == -1)
                return nt;
            if (!res)
                continue;
            q.push({nx, ny, nt});
            vvis[nx][ny]=1;
        }
    }
    return -1;
}

int main()
{
    input();
    std::cout << bfs() << endl;
    return 0;
}