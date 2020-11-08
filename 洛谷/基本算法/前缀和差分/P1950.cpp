#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1005;
int rect[maxn][maxn];
int n,m;
int stac[maxn],top=0;
int cur_bottle[maxn];
long long ans[maxn];
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)  
        {
            char ch=getchar();
            while(isspace(ch))
                ch=getchar();
            rect[i][j]= (ch=='*');
        }
}
long long solve(){
    long long res=(long long)(n)*(n+1)*m*(m+1)/4;
    for(int i=1;i<=n;i++)
    {
        memset(stac,0,sizeof(stac));
        for(int j=1;j<=m;j++)
        {
            if(rect[i][j]) cur_bottle[j]=i;
            while(top!=0 && cur_bottle[stac[top]] <= cur_bottle[j])
                top--;
            int k=stac[top];
            top++;
            stac[top]=j;
            ans[j]=ans[k]+(long long)(j-k)*cur_bottle[j];
            res-= ans[j];
        }
    }
    return res;
}
int main(){
    input();
    cout<<solve()<<endl;
    return 0;
}