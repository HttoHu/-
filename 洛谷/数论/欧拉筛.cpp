#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn=100000005;
int isnp[maxn];
int prime_table[maxn];
int cnt=1;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        if(!isnp[i])
            prime_table[cnt++]=i;
        for(int j=1;j<=cnt;j++)
        {
            int a=prime_table[j];
            if(i*a>n)
                break;
            isnp[i*a]=1;
            if(i%a==0)
                break;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int a;
        scanf("%d",&a);
        printf("%d\n",prime_table[a]);
    }
    return 0;
}