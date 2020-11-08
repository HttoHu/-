#include <iostream>
#include <algorithm>
int n,v;
int box[35];
int dp[20005];
int main(){
    using namespace std;
    cin>>v>>n;
    for(int i=0;i<n;i++)
        cin>>box[i];
    dp[0]=1;
    for(int i=0;i<n;i++)
        for(int j=v;j>=box[i];j--)
        {
            dp[j]|=dp[j-box[i]];
        }
    int ans;
    for(ans=v;ans>=0;ans--)
    {
        if(dp[ans])
            break;
    }
    std::cout<<v-ans<<std::endl;
}