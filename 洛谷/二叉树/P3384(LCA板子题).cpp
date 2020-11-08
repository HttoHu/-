/*
    最小公共祖先，在有根树种，两个节点u,v的公共祖先种距离最近的那个被称为最近公共祖先.
    我们可以用二分搜索。首先计算parent[k][v]表示自己向上走2^k的节点（祖先）

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 二叉树节点个数
int N,cnt=0;
// 输入两个数，表示u,v联通。最后一行是u,v 表示要计算u,v的最小公共祖先
const int maxn=500;
struct Edge
{
    int from,to;
}edges[maxn];
vector<int> G[maxn];
int par[15][maxn];
int depth[maxn];

int width[maxn];
int ans1=0,ans2=0;
void add_edge(int u,int v)
{
    edges[++cnt]={u,v};
    G[u].push_back(cnt);
}
void input(){
    cin>>N;
    for(int i=1;i<=N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add_edge(a,b);
        add_edge(b,a);
    }
}
void dfs(int u,int fa,int dep)
{
    par[0][u]=fa;
    depth[u]=dep;
    ans1=max(ans1,dep);
    width[dep]++;
    ans2=max(ans2,width[dep]);
    for(int i=0;i<G[u].size();i++)
    {
        auto &e=edges[G[u][i]];
        if(e.to!=fa)
            dfs(e.to,e.from,dep+1);
    }

}

void init()
{
    input();
    memset(par,-1,sizeof(par));
    dfs(1,-1,1);
    for(int k=0;k<10;k++)
        for(int v=1;v<=N;v++)
        {
            if(par[k][v] < 0) par[k+1][v]=-1;
            // 2^k+1 = 2^k + 2^k
            else{
                par[k+1][v]=par[k][par[k][v]];
            }
        }
}

int LCA(int u,int v)
{
    //让小的在后面
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=0;i<=10;i++)
    {
        // 你可以当成depth[u]-depth[v]为一个二进制数，如果是1的花就+ 2^i, +2^i就是par[i][v]咩
        if((depth[u]-depth[v])>> i &1)
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
    init();
    int u,v;
    cin>>u>>v;
    int pf=LCA(u,v);
    cout<<ans1<<endl<<ans2<<endl<<2*(depth[u]-depth[pf])+(depth[v]-depth[pf]);
    return 0;
}
