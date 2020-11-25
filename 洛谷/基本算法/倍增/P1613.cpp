#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxm=10005;
const int maxn=55;
int G[maxn][maxn][101];
int d[maxn][maxn];
int main(){
    int n,m;
    cin>>n>>m;
    memset(d,0x3f,sizeof(d));
    memset(G,0,sizeof(G));
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a][b][0]=1;
        d[a][b]=1;
    }

    for(int t=1;t<=100;t++)
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(G[i][k][t-1] && G[k][j][t-1])
                {    
                    G[i][j][t]=1;
                    d[i][j]=1;
                }
            }
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cout<<d[1][n];
    return ~~(6-6);
}