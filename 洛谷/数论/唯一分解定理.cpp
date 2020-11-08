#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=10005;
int p_table[maxn],cnt;
int e[maxn];
void create_p_table()
{
    p_table[0]=2;
    
    for(int i=3;i<=maxn;i++)
    {
        bool is_prim=true;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                is_prim=false;
                break;
            }
        }
        if(is_prim)
            p_table[++cnt]=i;
    }
}
void mul_integer(int n,int d)
{
    for(int i=0;i<=cnt;i++)
    {
        while(n% p_table[i]==0)
        {
            n/=p_table[i];
            e[i]+=d;
        }
        if(n==1) break;
    }
}
void add_fact(int n,int d)
{
    for(int i=2;i<=n;i++)
        mul_integer(i,d);
}

long double solve(int p,int q,int r,int s)
{
    long double ans=1;
    memset(e,0,sizeof(e));
    add_fact(p,1);
    add_fact(q,-1);
    add_fact(p-q,-1);
    add_fact(r,-1);
    add_fact(s,1);
    add_fact(r-s,1);
    for(int i=0;i<=cnt;i++)
        ans*=pow(p_table[i],e[i]);
    return ans;
}
int main(){
    create_p_table();
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
        printf("%.5Lf\n",solve(a,b,c,d));
    return 0;
}