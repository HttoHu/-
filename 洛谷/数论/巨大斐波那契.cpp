#include <iostream>
#include <fstream>
std::ofstream ofs("out.txt");
std::ifstream ifs("input.txt");
#define ofs std::cout
#define ifs std::cin
using ll=unsigned long long;
const int maxn=1005;
ll f[maxn][10*maxn];
ll p[maxn];
int pow_mod(ll a,ll n,int m)
{
    if(n==0) return 1;
    int x=pow_mod(a,n/2,m);
    x=x*x%m;
    if(n%2) x=x*a%m;
    return x;
}
ll solve(ll a,ll b,int n)
{
    if(n==1 || a==0)
        return 0;
    int t=pow_mod(a% p[n],b,p[n]);
    return f[n][t];
}
int main(){
    int kase;
    ifs>>kase;
    for(int i=2;i<=1000;i++)
    {
        f[i][0]=0;
        f[i][1]=1;
        for(int j=2;;j++)
        {
            f[i][j]=(f[i][j-1]+f[i][j-2])%i;
            if(f[i][j]==1 && f[i][j-1]==0)
            {
                p[i]=j-1;
                break;
            }
        }
    }
    while(kase--)
    {
        ll a,b;
        int n;
        ifs>>a>>b>>n;
        ofs<<solve(a,b,n)<<std::endl;
    }
    return 0;
}