#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
// N 行M 列
const int maxn=55;
// 0 是 北，1是东
int G[maxn][maxn][2];
int vis[maxn][maxn];
int dvis[maxn][maxn];
// 左，上，下，右
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
void input(){
    cin>>M>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            int a;
            cin>>a;
            G[i][j][0]=a&2;
            G[i][j][1]=a&4;
        }
    }
}
struct Result
{
    int rom_cnt;
    int max_rom;
};
bool check(int x,int y,int dir)
{
    if(x<=0 || y<=0 || x>N || y>M)
        return false;
    if( (x==1 && dir==1)
    ||  (y==1 && dir==0)
    ||  (x==N && dir==2)
    ||  (y==M && dir==3))
        return false;
    switch(dir){
    case 0:
        return !G[x][y-1][1];
    case 1:
        return !G[x][y][0];
    case 2:
        return !G[x+1][y][0];
    case 3:
        return !G[x][y][1];
    default:
        return false;
    }
}
int count_p(int x,int y,int cur){
    if(vis[x][y]!=0)
        return 0;
    int res=1;
    vis[x][y]=cur;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(vis[nx][ny]!=0)
            continue;
        if(nx <=0 || ny <= 0 || nx >N || ny >M )
            continue;
        if(!check(x,y,i))
            continue;
        res+=count_p(nx,ny,cur);
    }
    return res;
}

Result count(){
    int cnt=0;
    int ans=0;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            if(!vis[i][j])
            {
                ans=max(ans,count_p(i,j,++cnt));
            }
        }
    memset(vis,0,sizeof(vis));
    return {cnt,ans};
}
using RESTYPE=tuple<int,int,int,int>;
// x, y , DIR , MAX_ROM
bool operator>(RESTYPE r,RESTYPE e){
    return get<3>(r)>get<3>(e);
}
tuple<int,int,int,int> dfs(int x,int y)
{
    dvis[x][y]=1;
    tuple <int,int,int,int> res={x,y,-1,count().max_rom};
    if(G[x][y][0])
    {
        G[x][y][0]=0;
        auto tmp=count();
        G[x][y][0]=1;
        if(tmp.max_rom>get<3>(res))
        {
            get<2>(res)=0;
            get<3>(res)=tmp.max_rom;
        }
    }
    if(G[x][y][1])
    {
        G[x][y][1]=0;
        auto tmp=count();
        G[x][y][1]=1;
        if(tmp.max_rom>get<3>(res))
        {
            get<2>(res)=1;
            get<3>(res)=tmp.max_rom;
        }
    }
    return res;
}
tuple<int,int,int,int> solve(){
    tuple<int,int,int,int> res=dfs(N,1);
    for(int i=1;i<=M;i++)
        for(int j=N;j>=1;j--)
        {
            auto tmp=dfs(j,i);
            if(tmp>res)
                res=tmp;
        }
    return res;
}
int main(){
    input();
    auto res0=count();
    std::cout<<res0.rom_cnt<<endl<<res0.max_rom<<endl;
    auto res=solve();
    std::cout<<get<3>(res)<<endl<<get<0>(res)<<" "<<get<1>(res)<<" ";
    if(get<2>(res)==0)
        cout<<"N\n";
    else 
        cout<<"E\n";
    return 0;
}
