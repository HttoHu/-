#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int maxn=5005;
int f[maxn];
int a[maxn];
int ans[maxn];
int n;
int ans1=-1,ans2=0x3f3f3f3f;
int check(int k)
{
    memset(f,0,sizeof(f));
    int sum=0;
    int cnt=0;
    for(int i=0;i+k-1<n;i++)
    {
        if((sum+a[i])%2 != 0)
        {
            cnt++;
            f[i]=1;
        }
        sum+=f[i];
        if(i-k+1 >=0 )
            sum-=f[i-k+1];
    }
    for(int i=n-k+1;i<n;i++){
        if((sum+a[i])%2 != 0)
            return -1;
        if(i-k+1>=0)
            sum-=f[i-k+1];
    }
    return cnt;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char ch=getchar();
        while(isspace(ch)) ch=getchar();
        a[i]= (ch=='B');
    }
    for(int k=1;k<=n;k++)
    {
        int res=check(k);
        // cout<<"RES:"<<res<<endl;
        if(res==-1) continue;
        if(res < ans2)
        {
            ans1=k;
            ans2=res;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}