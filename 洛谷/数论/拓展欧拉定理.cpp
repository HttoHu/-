#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll=long long;
bool big_enough=false;
ll get_num(string str,ll mod){
    ll res=0;
    for(auto a:str)
    {
        res=res*10+a-'0';
        if(res>=mod)
        {
            big_enough=true;
            res%=mod;
        }
    }
    return res;
}
ll phi(ll x){
    ll res=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            res=res/i*(i-1);
        while(x%i==0)
            x/=i;
    }
    if(x>1)
        res=res/x*(x-1);
    return res;
}
ll mpow(ll a,ll b,ll p)
{
    if(b==0)
        return 1;
    if(b==1)
        return a%p;
    ll res=mpow(a,b/2,p);
    res=res*res%p;
    if(b%2)
        return res*a%p;
    return res;
}
int main(){
    string x,y,z;
    cin>>x>>y>>z;
    ll a=get_num(x,1e9+7),m=get_num(y,1e9+7),  phi_m=phi(m);
    ll b=get_num(z,phi_m);

    if(!big_enough)
        cout<<mpow(a,b,m);
    else
        cout<<mpow(a,b+phi_m,m);
    return 0;
}