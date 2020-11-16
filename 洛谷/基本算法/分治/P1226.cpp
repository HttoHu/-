#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
using ll=long long;
ll pow_mod(ll a,ll b,ll mod)
{
    if(b==0)
        return 0;
    if(b==1)
        return a%mod;
    ll h=pow_mod(a,b/2,mod);
    if(b%2)
        return (a%mod)*(h*h)%mod;
    return h*h%mod;
}
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    printf("%lld^%lld mod %lld=%lld",a,b,c,pow_mod(a,b,c));
    return 0;
}