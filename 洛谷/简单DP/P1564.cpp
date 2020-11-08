#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
const int maxn=2505;
int a[maxn];
int f[maxn];
int sum[maxn];
void input()
{
    cin>>N>>M;
    sum[0]=0;
    for(int i=1;i<=N;i++)
    {    
        cin>>a[i];
        if(a[i]==2)
            a[i]=-1;
        sum[i]+=sum[i-1]+a[i];
    }
}

int solve(){
    f[0]=0;
    for(int i=1;i<=N;i++)
    {
        f[i]=f[i-1]+1;
        for(int j=i-1;j>=0;j--)
        {
            int s=std::abs(sum[j]-sum[i]);
            if(s==(i-j) || s<= M)
                f[i]=min(f[i],f[j]+1);
        }
       // std::cout<<"嗐:"<<f[i]<<std::endl;
    }
    return f[N];
}

int main(){
    input();
    std::cout<<solve();
    return 0;
}