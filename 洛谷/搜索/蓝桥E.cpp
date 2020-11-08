#include <iostream>
#include <vector>
using namespace std;
const int maxn=10005;
struct Edge{
    int front,to;
}edges[maxn];
int cnt=1;
vector<int> G[maxn];
int vis[maxn];
int ans_arr[maxn];
void add_edge(int u,int v)
{
    edges[++cnt]={u,v};
    edges[++cnt]={v,u};
    G[u].push_back(cnt-1);
    G[v].push_back(cnt);
}
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        Edge &e =edges[G[u][i]];
        if(vis[e.to]==-1)
            dfs(e.to);
    }
}
bool test(int x)
{
    memset(vis,0,sizeof(vis));
    int i=1;
    int last=1;
    int cc=0;
    while(x)
    {
        if(x&1) 
        {
            last=i;
            vis[i]=-1;
            cc++;
        }
        i++;
        x>>=1;
    }
    dfs(last);
    for(int i=1;i<=7;i++)
        if(vis[i]==-1)
            return 0;
    for(int i=1;i<=7;i++)
        if(vis[i]==1)
            printf("%d ",i);
    printf("\n");
    return 1;
}

int main(){
    add_edge(1,2);
    add_edge(1,6);
    add_edge(2,7);
    add_edge(2,3);
    add_edge(3,4);
    add_edge(3,7);
    add_edge(4,5);
    add_edge(5,6);
    add_edge(5,7);
    add_edge(6,7);
    int ans=0;
    for(int i=1;i<(1<<7);i++)
        ans+=test(i);
    cout<<ans;
    return 0;
}