#include <vector>
#include <queue>
#include <iostream>
#include <string>
/*
还免费加了步骤，嘎嘎嘎
e2 e4
2 steps:
(4,1)(2,2)(4,3)
a1 b2
4 steps:
(0,0)(2,1)(0,2)(2,3)(1,1)
b2 c3
2 steps:
(1,1)(0,3)(2,2)
a1 h8
6 steps:
(0,0)(2,1)(0,2)(2,3)(4,4)(6,5)(7,7)
a1 h7
5 steps:
(0,0)(2,1)(1,3)(3,4)(5,5)(7,6)
h8 a1
6 steps:
(7,7)(5,6)(3,7)(4,5)(2,4)(1,2)(0,0)
b1 c3
1 steps:
(1,0)(2,2)
f6 f6
2 steps: 答案是0，因为它没走。。。。。。
(5,5)(3,6)(5,5)
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6 额不高兴改了，其实你说把，不走是不是不太妙额。。。。。
*/
using namespace std;
int vis[8][8];
bool inside(int x, int y)
{
    return x < 8 && y < 8 && x >= 0 && y >= 0;
}
struct Coor
{
    int x = -1;
    int y = -1;
    Coor(int _x, int _y) : x(_x), y(_y) {}
    Coor() {}
};
Coor back_path[8][8];
int dx[] = {-2, -1, 2, 1, -2, -1, 2, 1};
int dy[] = {1, 2, -1, -2, -1, -2, 1, 2};
int x, y;
int dest_x, dest_y;
bool bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            pair<int, int> walker = {u.first + dx[i], u.second + dy[i]};
            if (vis[walker.first][walker.second] || !inside(walker.first, walker.second))
                continue;
            if (walker.first == dest_x && walker.second == dest_y)
            {
                back_path[walker.first][walker.second] = Coor(u.first, u.second);
                return true;
            }
            back_path[walker.first][walker.second] = Coor(u.first, u.second);
            vis[walker.first][walker.second] = 1;
            q.push(walker);
        }
    }
    return false;
}
void solution()
{
    vector<Coor> solu;
    Coor u = back_path[dest_x][dest_y];
    solu.push_back(Coor(dest_x, dest_y));
    while (u.x != x || u.y != y)
    {
        solu.push_back(u);
        u = back_path[u.x][u.y];
    }
    solu.push_back(Coor(x, y));
    cout << solu.size() - 1 << " steps:\n"; //print incluing begin_node ,so min 1 is the actual steps.
    for (int i = solu.size() - 1; i >= 0; i--)
    {
        cout << "(" << solu[i].x << "," << solu[i].y << ")";
    }
    cout<<endl;
}
int main()
{
    while (true)
    {
        string str1;
        cin >> str1;
        x = str1[0] - 'a';
        y = str1[1] - '1';
        cin >> str1;
        dest_x = str1[0] - 'a';
        dest_y = str1[1] - '1';
        if (!bfs())
        {
            cout << "IMPOSSIBLE!";
        }
        else
        {
            solution();
        }
    }
    return 0;
}
