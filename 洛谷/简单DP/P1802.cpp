#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N,X;
const int maxn=1005;
int lose[maxn],win[maxn],cost[maxn];
long long dp[maxn];
int main(){
    cin>>N>>X;
    for(int i=1;i<=N;i++)
        cin>>lose[i]>>win[i]>>cost[i];
    for(int i=1;i<=N;i++)
        for(int j=X;j>=0;j--)
        {
            if(j<cost[i])
                dp[j]=dp[j]+lose[i];
            else 
                dp[j]=max(dp[j]+lose[i],dp[j-cost[i]]+win[i]);
        }
    std::cout<<dp[X]*5;
    return 0;
}