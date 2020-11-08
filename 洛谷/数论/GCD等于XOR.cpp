#include <iostream>
#include <vector>
using namespace std;
const int maxn=3e7;
int f[maxn+5];
void solve(int n)
{
    int k=(n>>1);
    for(int b=1;b<=k;b++)
        for(int a=2*b;a<=n;a+=b)
        {
            if((a-b)==(a^b))
                f[a]++;
        }
    for(int i=1;i<=n;i++)
        f[i]+=f[i-1];
}
int main()
{
    int kase = 0;
    solve(maxn);
    cin >> kase;
    for(int k=1;k<=kase;k++)
    {
        int t;
        cin >> t;
        printf("Case %d: %d\n",k,f[t]);
    }
    return 0;
}