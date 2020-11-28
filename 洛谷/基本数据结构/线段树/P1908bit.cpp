#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <cstring>
using namespace std;
using ll=long long;
const ll maxn=1000005;
ifstream ifs("input.txt");
ll lowbit(ll x){
    return x&(-x);
}
ll bit[maxn];
struct unit{
    ll value;
    ll idx;
    bool operator<(const unit&u)const{
        if(value==u.value)
            return idx > u.idx;
        return value>u.value;
    }
}f[maxn];
ll n;
void add(ll p,ll x)
{
    while(p<=n){
        bit[p]+=x;
        p+=lowbit(p);
    }
}
ll query(ll p)
{
    ll res=0;
    while(p>0)
    {
        res+=bit[p];
        p-=lowbit(p);
    }
    return res;
}
int main(){
    cin>>n;
    memset(bit,0,sizeof(bit));
    for(ll i=1;i<=n;i++)
    {
        cin>>f[i].value;
        f[i].idx=i;
    }
    sort(f+1,f+n+1);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        add(f[i].idx,1);
        ans+=query(f[i].idx-1);
    }
    printf("%lld",ans);
    return 0;
}
