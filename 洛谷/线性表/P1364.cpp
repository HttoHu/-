#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 200;
int csize[maxn];
int d[maxn];
int fa[maxn];
int counts[maxn];
int N, cnt = 0;
struct Edge
{
    int u, v;
} edges[10 * maxn];
vector<int> G[maxn];
void add_edge(int u, int v)
{
    edges[++cnt] = {u, v};
    G[u].push_back(cnt);
}
void build_tree()
{
    cin >> N;
    fill(csize + 1, csize + N + 1, 1);
    
    for (int i = 1; i <= N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        counts[i]=csize[i]=a;
        if (b)
        {
            add_edge(i, b);
            add_edge(b, i);
        }
        if(c){
            add_edge(i, c);
            add_edge(c, i);
        }
    }
}
void dfs(int u,int par,int dep)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        auto &e = edges[G[u][i]];
        if (e.v == par)
            continue;
        dfs(e.v,e.u,dep+1);
        csize[u] += csize[e.v];
    }
    d[1] += dep * counts[u];
}

void dp(int u,int par)
{

    for (int i = 0; i < G[u].size(); i++)
    {
        auto &e = edges[G[u][i]];
        if (e.v == par)
            continue;
        d[e.v] = d[e.u] - csize[e.v] + (csize[1] - csize[e.v]);
        dp(e.v,u);
    }
}
int main()
{
    build_tree();
    dfs(1,0, 0);
    dp(1,0);
    int ans = d[1];
    for (int i = 1; i <= N; i++)
        ans = min(ans, d[i]);
    std::cout << ans << endl;
    return 0;
}