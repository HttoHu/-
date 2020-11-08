#include <iostream>
#include <vector>
#include <algorithm>
const int maxn=105;
int t[maxn],c[maxn];
int dp[1005];
int T,M;
int main(){
    using namespace std;
    cin>>T>>M;
    for(int i=0;i<M;i++){
        cin>>t[i]>>c[i];
    }
    for(int i=0;i<M;i++)
        for(int j=T;j>=t[i];j--)
          dp[j]=max(dp[j],dp[j-t[i]]+c[i]);
    std::cout<<dp[T];
    return 0;
}