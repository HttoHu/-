#include <iostream>
#include <vector>
const int maxn=10005;
int par[maxn];
int rak[maxn];
int vis[maxn];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rak[i]=0;
    }
}

int find(int x){
    if(par[x]==x)
        return x;
    return par[x]=find(par[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rak[x]<rak[y])
    {
        vis[y]=1;
        par[x]=y;
    }
    else{
        vis[x]=1;
        par[y]=x;
        if(rak[x]==rak[y])
            rak[x]++;
    }
}

bool same(int x,int y)
{
    return find(x)==find(y);
}
bool solve()
{
    int n,m;
    memset(vis,0,sizeof(vis));
    memset(rak,0,sizeof(rak));
    memset(par,0,sizeof(par));
    std::cin>>n;
    if(n==0)
        return false;
    std::cin>>m;
    init(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        std::cin>>a>>b;
        unite(a,b);
    }
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(!same(i,1))
        {
            unite(i,1);
            cnt++;
        }
    }
    std::cout<<cnt<<std::endl;
    return true;
}
int main(){
    while(solve());
    return 0;
}