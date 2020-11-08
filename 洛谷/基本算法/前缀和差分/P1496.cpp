#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int maxn=40005;
int a[maxn];
int b[maxn];
int p[2*maxn];
int flag[2*maxn];
int m=1;
int find(int x){
    return lower_bound(p+1,p+1+m,x)-p;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        p[m]=a[i];
        m++;
        p[m]=b[i];
        m++;
    }
    m--;
    sort(p+1,p+m+1);
    // for(int i=1;i<=m;i++)
    //     cout<<p[i]<<" \n"[i==m];
    for(int i=1;i<=n;i++)
    {
        a[i]=find(a[i]);
        b[i]=find(b[i])-1;
        for(int j=a[i];j<=b[i];j++)
            flag[j]=1;
    }
    long long res=0;
    for(int i=1;i<=m;i++)
        if(flag[i])
            res+=p[i+1]-p[i];
    cout<<res;
    return 0;
}