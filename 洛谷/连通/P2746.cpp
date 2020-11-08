#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
    int from,to;
};
const int maxn=1005;
int dfn[maxn],low[maxn],ti=0;
int vis[maxn],ng[maxn],idx=0;
int cnt[maxn],rd[maxn],od[maxn];
vector<Edge> edges;
vector<int> G[maxn],stac;
void add_edge(int u,int v)
{
    edges.push_back({u,v});
    G[u].push_back(edges.size()-1);
}
void tarjan(int u)
{
    dfn[u]=low[u]=++ti;
    vis[u]=1;
    stac.push_back(u);
    for(int i=0;i<G[u].size();i++){
        int v=edges[G[u][i]].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) 
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++idx;
        int v;
        while(v=stac.back())
        {
            stac.pop_back();
            vis[v]=0;
            ng[v]=idx;
            cnt[idx]++;
            if(u==v)
                break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        while(cin>>a && a)
            add_edge(i+1,a);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=0;i<edges.size();i++)
    {
        int u=ng[edges[i].from],v=ng[edges[i].to];
        if(u==v)
            continue;
        od[u]++;
        rd[v]++;
    }
    int id_zc=0,od_zc=0,pp_b=0;
    for(int i=1;i<=idx;i++)
    {
        if(rd[i]==0)
            id_zc++;
        if(od[i]==0)
            od_zc++;
        if(cnt[i]==n)
            pp_b=1;
    }
    if(pp_b)
    {
        cout<<id_zc<<endl<<0<<endl;
        return 0;
    }
    cout<<id_zc<<endl<<max(id_zc,od_zc)<<endl;
    return 0;
}

