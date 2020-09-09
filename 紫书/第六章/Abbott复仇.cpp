//我来默写啦，额，好像是第二次默写了呜呜呜
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
/*
DAMN
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
*/
using namespace std;
const int maxn = 10;
int my_map[maxn][maxn][4][3];
const char *dirs = "NESW";
const char *turns = "FLR";
struct Node;
void print_ans(Node u);
bool inside(int r, int c)
{
    return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}
int dir_id(char c)
{
    return strchr(dirs, c) - dirs;
}
int turn_id(char c)
{
    return strchr(turns, c) - turns;
}
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
struct Node
{
    int r;
    int c;
    int dir;
};
Node begin_node;
Node end_node;
int d[maxn][maxn][4];
Node back_path[maxn][maxn][4];
Node walk(const Node &u, int turn)
{
    int dir = u.dir;
    if (turn == 1)
        dir = (dir + 3) % 4; // 逆时针
    if (turn == 2)
        dir = (dir + 1) % 4; // 顺时针
    return Node{u.r + dr[dir], u.c + dc[dir], dir};
}
int r1, c1;
bool read_case()
{
    char s[99], s2[99];
    if (scanf("%s%d%d%s%d%d", s, &begin_node.r, &begin_node.c, s2, &end_node.r, &end_node.c) != 6)
        return false;
    printf("%s\n", s);

    begin_node.dir = dir_id(s2[0]);
    r1 = begin_node.r + dr[begin_node.dir];
    c1 = begin_node.c + dc[begin_node.dir];

    memset(my_map, 0, sizeof(my_map));
    for (;;)
    {
        int r, c;
        scanf("%d", &r);
        if (r == 0)
            break;
        scanf("%d", &c);
        while (scanf("%s", s) == 1 && s[0] != '*')
        {
            for (int i = 1; i < strlen(s); i++)
                my_map[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
        }
    }
    return true;
}

void input()
{
    memset(my_map, 0, sizeof(my_map));
    cin >> begin_node.r;
    cin >> begin_node.c;
    char tmp;
    cin >> tmp;
    begin_node.dir = dir_id(tmp);
    cin >> end_node.r >> end_node.c;
    r1 = begin_node.r + dr[begin_node.dir];
    c1 = begin_node.c + dc[begin_node.dir];
    while (true)
    {

        int r, c;
        cin >> r;
        if (r == 0)
        {
            return;
        }
        cin >> c;
        string info;
        while (true)
        {
            cin >> info;
            if (info == "*")
            {
                break;
            }
            int dir_mod = dir_id(info[0]);
            for (int i = 1; i < info.size(); i++)
            {
                my_map[r][c][dir_mod][turn_id(info[i])] = 1;
            }
        }
    }
}
void bfs()
{
    queue<Node> que;
    que.push(Node{r1,c1,begin_node.dir});
    memset(d, -1, sizeof(d));
    d[r1][c1][begin_node.dir] = 0;
    while (!que.empty())
    {
        Node cur = que.front();
        que.pop();
        if (cur.r == end_node.r && cur.c == end_node.c)
        {
            print_ans(cur);
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            Node w = walk(cur, i);
            if (my_map[cur.r][cur.c][cur.dir][i] && inside(w.r, w.c) && d[w.r][w.c][w.dir] < 0)
            {
                d[w.r][w.c][w.dir] = d[cur.r][cur.c][cur.dir] + 1;
                back_path[w.r][w.c][w.dir] = cur;
                que.push(w);
            }
        }
    }
    cout << "NO SOLUTION";
}

void print_ans(Node cur)
{
    vector<Node> results;
    while (true)
    {
        results.push_back(cur);
        if (d[cur.r][cur.c][cur.dir] == 0)
            break;
        cur = back_path[cur.r][cur.c][cur.dir];
    }
    results.push_back(begin_node);
    for (auto a : results)
    {
        std::cout << "(" << a.r << "," << a.c << ")";
    }
}
void solve()
{
    queue<Node> q;
    memset(d, -1, sizeof(d));
    Node u{r1, c1, begin_node.dir};
    d[u.r][u.c][u.dir] = 0;
    q.push(u);
    while (!q.empty())
    {
        Node u = q.front();
        q.pop();
        if (u.r == end_node.r && u.c == end_node.c)
        {
            print_ans(u);
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            Node v = walk(u, i);
            if (my_map[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0)
            {
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                back_path[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}
int main()
{
    input();
    bfs();
    return 0;
}