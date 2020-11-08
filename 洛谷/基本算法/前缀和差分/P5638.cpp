#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000005;
long long s[maxn];
int n,k;
int main(){
    cin>>n>>k;
    memset(s,0,sizeof(s));
    for(int i=1;i<=n-1;i++)
    {
        long long a;
        cin>>a;
        s[i]=s[i-1]+a;
    }
    long long res=0;
    for(int i=0;i+k<=n-1;i++)
    {
        res=max(res,s[i+k]-s[i]);
    }
    cout<<s[n-1]-res;
    return 0;
}