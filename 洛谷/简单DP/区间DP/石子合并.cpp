#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1005;
int n;
int arr[maxn];
int f[maxn][maxn];
int mf[maxn][maxn];
int sum[maxn];
int calc(int i,int j)
{
    return sum[j]-sum[i-1];
}
int main(){
    cin>>n;
    memset(mf,0x3f,sizeof(mf));
    memset(sum,0,sizeof(sum));
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {   
        cin>>arr[i];
        arr[i+n]=arr[i];
        sum[i]=sum[i-1]+arr[i];
        mf[i][i]=mf[i+n][i+n]=0;
    }
    for(int i=n+1;i<=2*n;i++)
        sum[i]=sum[i-1]+arr[i];
    for(int k=1;k<2*n;k++)
        for(int i=1;i+k<=2*n;i++)
        {
            int j=k+i;
            for(int x=i;x+1<=j;x++)
            {
                int s=calc(i,j);
                f[i][j]=max(f[i][j],f[i][x]+f[x+1][j]+s);
                mf[i][j]=min(mf[i][j],mf[i][x]+mf[x+1][j]+s);
            }
        }
    int min_res=0x3f3f3f3f;
    int max_res=0;
    for(int i=1;i<=n;i++)
    {
        max_res=max(max_res,f[i][i+n-1]);
        min_res=min(min_res,mf[i][i+n-1]);
    }
    cout<<min_res<<endl<<max_res<<endl;
    return 0;
}