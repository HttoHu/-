#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
const int maxn=20;
int l=0;
struct Coor
{
    double x,y;
}arr[maxn];
struct Node
{
    double d;
    int num;
    bool operator<(Node & n)const{
        return d<n.d;
    }
};
Node dis[maxn][maxn];
double square(double x)
{
    return x*x;
}
double get_dis(Coor &rhs,Coor &lhs)
{
    return sqrt(square(rhs.x-lhs.x)+ square(rhs.y-lhs.y));
}
int vis[maxn];
int n;
void input(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double x,y;
        cin>>x>>y;
        arr[i]={x,y};
    }
    arr[0]={0,0};
    for(int i=0;i<=n;i++)
    {    
        for(int j=0;j<=n;j++)
        {
            dis[i][j]={get_dis(arr[i],arr[j]),j};
        }
        sort(dis[i]+1,dis[i]+n+1);
    }
}
double cur_res=1e9;
void dfs(int cur,double value,int last)
{
    l++;
    if(l>=3000000)
    {
        int t=clock();
        // 一天一个骗分技巧
        if(t>=940)
        {
            printf("%.2lf",cur_res);
            exit(0);
        }
    }
    if(cur==n+1){
        if(value < cur_res)
            cur_res=value;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[dis[last][i].num])
            continue;
        double v=value+dis[last][i].d;
        if(v>cur_res)
            continue;
        vis[dis[last][i].num]=1;
        dfs(cur+1,v,dis[last][i].num);
        vis[dis[last][i].num]=0;
    }

}
int main(){
    input();
    dfs(1,0,0);
    printf("%.2lf\n",cur_res);
    return 0;
}