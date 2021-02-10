#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll res=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}
int main(){
    ll x,y,m,n,L;
    cin>>x>>y>>m>>n>>L;
    ll w=n-m,S=x-y;
    if(w <0)
        w=-w,S=-S;
    ll res=exgcd(w,L,x,y);
    ll k=S/res;
    ll mod=L/res;
    if(S%res!=0)
        cout<<"Impossible\n";
    else 
        cout<<(x*k%mod+mod)%mod;
    return 0;
}