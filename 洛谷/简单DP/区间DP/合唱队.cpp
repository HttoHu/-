#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int maxn=1005;
const int mod=19650827;
int arr[maxn];
long long f[maxn][maxn][2];
// 1 上一个在左边
// 0 上一个在右边
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        f[i][i][1]=1;
    }
    for(int k=1;k<n;k++)
        for(int i=1;i+k<=n;i++)
        {
            int j=i+k;
            int r=arr[j],l=arr[i];
            if(arr[i]<r)
                f[i][j][0]+=f[i][j-1][1];
            if(arr[j-1]<r)
                f[i][j][0]+=f[i][j-1][0];
            if(arr[i+1]>l)
                f[i][j][1]+=f[i+1][j][1];
            if(arr[j]>l)
                f[i][j][1]+=f[i+1][j][0];
            f[i][j][1]%=mod;
            f[i][j][0]%=mod;
        }
    cout<<(f[1][n][0]+f[1][n][1])%mod;
}