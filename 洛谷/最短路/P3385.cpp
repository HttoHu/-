#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
const int maxn = 30050;
const int maxm = 20050;
using namespace std;
struct Edge
{
    int from, to, value;
} edges[maxm];
int edge_cnt = 1;
vector<int> G[maxn];
void add_edge(int x, int y, int v)
{
    edges[edge_cnt] = {x, y, v};
    G[x].push_back(edge_cnt);
    edge_cnt++;
}

int vis[maxn];
int cnt[maxn];
int d[maxn];
int N, M;
bool spfa()
{
    queue<int> q;
    memset(d, 0x3f, sizeof(d));
    q.push(1);
    vis[1] = 1;
    d[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        vis[cur] = 0;
        for (int i = 0; i < G[cur].size(); i++)
        {
            auto &e = edges[G[cur][i]];
            if (d[e.to] > d[cur] + e.value)
            {
                d[e.to] = d[cur] + e.value;
                if (!vis[e.to])
                {
                    if (cnt[e.to]++ > N)
                        return false;
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
    return true;
}
void input()
{
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    edge_cnt = 1;
    for (auto &a : G)
        a.clear();
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
        if (c >= 0)
        {
            add_edge(b, a, c);
        }
    }
}

int main()
{
    int kase;
    cin >> kase;
    while (kase--)
    {
        input();
        if (spfa())
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
    return 0;
}