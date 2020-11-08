#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int N,M;
const int maxn=100005;
int sticks[maxn];
void input(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)        
        scanf("%d",sticks+i);
}           

bool check(int l)
{
    int res=0;
    for(int i=1;i<=N;i++)
        if(sticks[i]<l)
            continue;
        else 
            res+=sticks[i]/l;
    if(res >= M)
        return true;
    return false;
}

int main(){
    input();
    int L=1,R=100000005;
    while(L<R)
    {
        int m=(L+R)/2;
        if(check(m))
            L=m+1;
        else 
            R=m;
    }
    printf("%d\n",L-1);
    return 0;
}