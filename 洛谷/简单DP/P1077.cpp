#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[105];
int f[105][105];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++) f[i][0]=1;
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=min(a[i],j);k++)
            {
                f[i+1][j]+=f[i][j-k];
                f[i+1][j]%=1000007;
            }
        }
    std::cout<<f[n][m]%1000007<<std::endl;
}