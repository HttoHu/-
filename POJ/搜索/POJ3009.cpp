// 0 vacent square
// 1 block
// 2 start position
// 3 goal position
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
vector<int> ans;
const int maxn = 21;
int W, H;
struct Pos
{
    Pos(){}
    Pos(int _x, int _y) : x(_x), y(_y) {}
    int x, y;
    bool operator==(const Pos &p)
    {
        return x == p.x && y == p.y;
    }
    void print()
    {
        std::cout << "(" << x << "," << y << ")";
    }
} s_pos, e_pos;
int raw[maxn][maxn];
int cur[maxn][maxn];
bool input()
{
    cin >> W >> H;
    if (W == 0 && H == 0)
        return false;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> raw[j][i];
            if (raw[j][i] == 2)
                s_pos = Pos(j, i);
            else if (raw[j][i] == 3)
                e_pos = Pos(j, i);
        }
    }
    return true;
}
/*
1 up
2 down
3 left
4 right

*/
void change(int x, int y, int dir, int v)
{
    if (dir == 1)
        cur[x][y - 1] = v;
    else if (dir == 2)
        cur[x][y + 1] = v;
    else if (dir == 3)
        cur[x - 1][y] = v;
    else if (dir == 4)
        cur[x + 1][y] = v;
}
Pos walk(int x, int y, int dir)
{
    if (dir == 1)
    {
        for (int i = y - 1; i >= 0; i--)
        {
            if (cur[x][i] == 1)
            {
                if (i == y - 1)
                    break;
                else
                    return Pos(x, i + 1);
            }
            else if (cur[x][i] == 3)
                return e_pos;
        }
    }
    else if (dir == 2)
    {
        for (int i = y + 1; i < H; i++)
        {
            if (cur[x][i] == 1)
            {
                if (i == y + 1)
                    break;
                else
                    return Pos(x, i - 1);
            }
            else if (cur[x][i] == 3)
                return e_pos;
        }
    }
    else if (dir == 3)
    {
        for (int i = x - 1; i >= 0; i--)
        {
            if (cur[i][y] == 1)
            {
                if (i == x - 1)
                    break;
                else
                    return Pos(i + 1, y);
            }
            else if (cur[i][y] == 3)
                return e_pos;
        }
    }
    else if (dir == 4)
    {
        for (int i = x + 1; i < W; i++)
        {
            if (cur[i][y] == 1)
            {    
                if (i == x + 1)
                    break;
                else
                    return Pos(i - 1, y);
            }
            else if (cur[i][y] == 3)
                return e_pos;
        }
    }
    return Pos(-1, -1);
}
void print_cur()
{
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            std::cout << cur[i][j] << " \n"[j == W - 1];
}
int dfs(int x, int y, int depth)
{
    if (depth > 10)
        return -1;
    int ans = 11;
    for (int i = 1; i <= 4; i++)
    {
        Pos result = walk(x, y, i);
        if (result == e_pos)
            return depth;
        else if (result.x == -1)
            continue;
        change(result.x, result.y, i, 0);
        int cur_ans = dfs(result.x, result.y, depth + 1);
        change(result.x, result.y, i, 1);
        if (cur_ans == -1)
            continue;
        ans = min(ans, cur_ans);
    }
    if (ans <= 10)
        return ans;
    else
        return -1;
}
int solve()
{
    for (int i = 0; i < maxn; i++)
        memcpy(cur[i], raw[i], sizeof(int) * maxn);
    return dfs(s_pos.x, s_pos.y, 1);
}

int main()
{
    while (input())
    {
        ans.push_back(solve());
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}