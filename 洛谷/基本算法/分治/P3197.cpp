#include <iostream>
const long long mod=100003;
using namespace std;
using ll=long long;
ll pow_mod(ll a,ll n)
{
    if(n==0)
        return 1;
    if(n==1)
        return a%mod;
    ll h=pow_mod(a,n/2);
    if(n%2)
        return ((a%mod)*(h*h)%mod)%mod;
    return (h*h)%mod;
}
int main(){
    long long n,m;
    cin>>m>>n;
    cout<<((pow_mod(m,n)-m*pow_mod(m-1,n-1))%mod+mod)%mod;
    return 0;
}