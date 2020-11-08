#include <iostream>
using namespace std;
using ll=long long;
ll exgcd(ll a,ll b,ll&x,ll&y)
{
    int d=a;
    if(b==0)
    {
        x=1,y=0;
        return d;
    }
    d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
int main(){
    ll a,b;
    cin>>a>>b;
    ll x,y;
    ll t=exgcd(a,b,x,y);
    cout<<((x%b)+b)%b<<endl;
    return 0;
}