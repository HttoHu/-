#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100005;
int p[maxn];
int a[maxn],b[maxn],c[maxn];
long long gc[maxn];
long long sum[maxn];
long long walk[maxn];
int n,m;
void process()
{
    walk[0]=0;
    for(int i=1;i<=n;i++)
        walk[i]+=walk[i-1];
    for(int i=2;i<=n;i++)
        gc[i]=min(walk[i]*b[i]+c[i],walk[i]*a[i]);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+gc[i];
}
int main(){
    cin>>n>>m;
    int last=0;
    for(int i=1;i<=m;i++)
        cin>>p[i];
    for(int i=2;i<=m;i++)
    {
        int l=min(p[i-1],p[i]),r=max(p[i-1],p[i]);
        walk[l+1]++;walk[r+1]--;
    }
    for(int i=2;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    process();
    cout<<sum[n]<<endl;
    return 0;
}