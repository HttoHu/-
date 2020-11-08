#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
/*
    我们可以倒着存，这样我们可以很容易确定最后一行，我们把它存到tree[0]
    y记作列坐标,x记作行坐标.fa为父节点，ls为左节点，rs为右节点
    然后我们发现，fa.y=(ls.y+rs.y)/2;
    再观察我们可以知道 |fa.x-ls.x|=|rs.y-ls.y|/2;
    有了这两个结论我们很容易把树倒着画出来了.
*/
using namespace std;
const int maxn = 2000;
char tree[maxn][maxn];
void draw(int n);
void erase(int d, int idx);
int n, m;
struct Pos
{
    int x = 0, y = 0;
    bool operator==(const Pos &p) const
    {
        return x == p.x && y == p.y;
    }
};
// pos_arr[r][c]记录第r层，第c-1个节点的坐标.
Pos pos_arr[15][maxn];
void draw(int n)
{
    vector<int> par_pos;
    int idx = 0, dep_cnt = pow(2, n - 1);
    int cur_dep = 0;
    for (int i = 1; i <= dep_cnt; i++)
    {
        pos_arr[n][i - 1] = {0, idx};
        tree[0][idx] = 'o';
        if (i & 1)
        {
            par_pos.push_back(idx);
            idx += 4;
        }
        else
        {
            par_pos.push_back(idx);
            idx += 2;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int branch_cnt = (par_pos[1] - par_pos[0]) / 2 - 1;
        dep_cnt = pow(2, n - i);
        for (int k = 0; k < dep_cnt; k++)
        {
            for (int j = 1; j <= branch_cnt; j++)
                if (!(k & 1))
                    tree[cur_dep + j][par_pos[k] + j] = '/';
                else
                    tree[cur_dep + j][par_pos[k] - j] = '\\';
            if (!(k & 1))
            {
                int nidx = (par_pos[k] + par_pos[k + 1]) / 2;
                tree[cur_dep + branch_cnt + 1][nidx] = 'o';
                pos_arr[n - i][k / 2] = {cur_dep + branch_cnt + 1, nidx};
                par_pos[k / 2] = nidx;
            }
        }
        cur_dep += branch_cnt + 1;
    }
}
void erase(int r, int c)
{
    if (c < 0 || r <= 0)
        return;
    Pos &p = pos_arr[r][c];
    if (r != n)
    {
        int len =p.x-pos_arr[r + 1][0].x;
        for (int i = 0; i <= len; i++)
            tree[p.x - i][p.y + i] = tree[p.x - i][p.y - i] = ' ';
        erase(r + 1, 2 * c);
        erase(r + 1, 2 * c + 1);
    }
    if (r != 1)
    {
        int len2 = pos_arr[r - 1][0].x-p.x;
        int delt = c & 1 ? -1 : 1;
        for (int i = 0; i < len2; i++)
            tree[p.x + i][p.y + i * delt] = ' ';
    }
}
int main()
{
    memset(tree, ' ', sizeof(tree));
    cin >> n >> m;
    draw(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        erase(a, b - 1);
    }
    int width = pow(2, n - 1) * 3;
    for (int i = width / 2 - 1; i >= 0; i--)
    {
        for (int j = 0; j < width; j++)
            printf("%c", tree[i][j]);
        printf("\n");
    }

    return 0;
}