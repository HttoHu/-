#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
ifstream ifs("input.txt");
ofstream ofs("output.txt");
#define cin ifs
#define cout ofs
int n, m;
struct Edge
{
    int u, v;
};
const int maxn = 100005;
vector<Edge> edges;
vector<int> G[maxn];
void add_edge(int u, int v)
{
    edges.push_back({u, v});
    G[u].push_back(edges.size() - 1);
}
int depth[maxn];
int par[maxn][15];
// H - 1 G - 0
int Hpar[maxn][15];
int Gpar[maxn][15];
int cows[maxn];
void dfs(int u, int fa, int d)
{
    par[u][0] = fa;
    if (fa != -1)
    {
        Hpar[u][0] = cows[u] || cows[fa];
        Gpar[u][0] = !cows[u] || !cows[fa];
    }
    else
    {
        Hpar[u][0] = cows[u];
        Gpar[u][0] = !cows[u];
    }
    depth[u] = d;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = edges[G[u][i]].v;
        if (v != fa)
            dfs(v, u, d + 1);
    }
}

void init()
{
    memset(par, -1, sizeof(depth));
    dfs(1, -1, 1);
    for (int k = 0; k <= 10; k++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (par[v][k] == -1)
            {
                par[v][k + 1] = -1;
                Gpar[v][k + 1] = Gpar[v][k];
                Hpar[v][k + 1] = Hpar[v][k];
            }
            else
            {
                par[v][k + 1] = par[v][par[v][k]];
                Gpar[v][k + 1] = Gpar[v][k] || Gpar[v][par[v][k]];
                Hpar[v][k + 1] = Hpar[v][k] || Hpar[v][par[v][k]];
            }
        }
    }
}
int LCA(int u, int v, int q)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int k = 1; k <= 10; k++)
    {
        if ((depth[u] - depth[v]) >> k & 1)
        {
            if (Hpar[u][k] && q || Gpar[u][k] && !q)
                return 1;
            u = par[u][k];
        }
    }
    if (u == v)
        return cows[u]==q;
    for (int k = 10; k >= 0; k--)
    {
        if (par[u][k] != par[v][k])
        {
            if (Hpar[u][k] && q || Gpar[u][k] && !q || Hpar[v][k] && q || Gpar[v][k] && !q)
                return 1;
            u = par[u][k];
            v = par[v][k];
        }
    }
    return Hpar[u][0] && q || Gpar[u][0] && !q || Hpar[v][0] && q || Gpar[v][0];
}

int main()
{
    cin >> n >> m;
    string str;
    cin >> str;
    for (int i = 1; i <= str.size(); i++)
        cows[i] = str[i - 1] == 'H';
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        add_edge(b, a);
    }
    init();
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        char ch;
        cin >> a >> b >> ch;
        cout << LCA(a, b, ch == 'H');
    }
    return 0;
}