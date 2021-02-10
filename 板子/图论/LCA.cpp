#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=100005;
struct Edge{
    int from,to;
};
vector<Edge> edges;
vector<int> G[maxn];
int depth[maxn];
int par[maxn][15];
int n,m;
void add_edge(int u,int v)
{
    edges.push_back({u,v});
    G[u].push_back(edges.size()-1);
}
void dfs(int u,int p,int dep)
{
    par[u][0]=p;
    depth[u]=dep;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(u!=v)
            dfs(v,u,dep+1);
    }
}
void init(){
    memset(par,-1,sizeof(par));
    dfs(1,-1,1);
    for(int k=0;k<10;k++)
        for(int v=1;v<=n;v++)
        {
            if(par[k][v]<0) par[k+1][v]=-1;
            else par[k+1][v]=par[k][par[k][v]];
        }
}

int LCA(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=0;i<=10;i++)
    {
        if((depth[u]-depth[v])>>i &1)
            u=par[i][u];
    }
    if(u==v)
        return u;
    for(int k=10;k>=0;k--)
    {
        if(par[k][u]!=par[k][v])
        {
            u=par[k][u];
            v=par[k][v];
        }
    }
    return par[0][v];
}
int main(){
    
}