#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=500005;
int a[maxn];
int f[maxn];
int rf[maxn];
int n,k;

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int res=0;
    int mf=0,mrf=0;
    for(int i=0;i<n;i++)
    {
        int ri=n-1-i;
        mf=max(mf,(int)((a+i+1)-lower_bound(a,a+n,a[i]-k)));
        mrf=max(mrf,(int)(upper_bound(a,a+n,a[ri]+k)-(a+ri)));
        f[i]=mf;
        rf[ri]=mrf;
    }
    for(int i=0;i<n;i++)
        res=max(res,f[i]+rf[i+1]);
    cout<<res;
    return 0;
}
