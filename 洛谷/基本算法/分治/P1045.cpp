#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
using ll=long long;
const ll t32=1LL<<32;
long long bits[1000];
int main(){
    int p;
    cin>>p;
    bits[500]=1;
    int cnt=p/32;
    int left=p%32;
    cout<<ceil((long double)p*log10(2.0))<<endl;
    for(int i=1;i<=cnt;i++)
    {
        for(int i=1;i<=500;i++)
            bits[i]*=t32;
        for(int i=500;i>=1;i--)
        {
            bits[i-1]+=bits[i]/10;
            bits[i]%=10;
        }
    }
    for(int i=1;i<=left;i++)
    {
        for(int i=1;i<=500;i++)
            bits[i]*=2;
        for(int i=500;i>=1;i--)
        {
            bits[i-1]+=bits[i]/10;
            bits[i]%=10;
        }
    }
    bits[500]--;
    for(int i=1;i<=500;i++)
    {
        cout<<bits[i];
        if(i%50==0) cout<<endl;
    }
    return 0;
}
