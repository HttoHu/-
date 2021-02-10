#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=100;
long long dp[maxn][maxn][2];
long long sum[maxn];
int p[maxn];
int w[maxn];
int n,c;
int except(int i,int j)
{
    return sum[i-1]+sum[n]-sum[j];
}
int main(){

    cin>>n>>c;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>w[i];
        sum[i]=sum[i-1]+w[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[c][c][1]=dp[c][c][0]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i+k<=n;i++)
        {
            int j=k+i;
            dp[i][j][1]=min(dp[i+1][j][1]+(p[i+1]-p[i])*except(i+1,j),dp[i+1][j][0]+(p[j]-p[i])*except(i+1,j));
            dp[i][j][0]=min(dp[i][j-1][0]+except(i,j-1)*(p[j]-p[j-1]),dp[i][j-1][1]+except(i,j-1)*(p[j]-p[i]));
        }
    cout<<min(dp[1][n][1],dp[1][n][0]);
    return 0;
}