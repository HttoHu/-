#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int maxn=1005;
int G[maxn][maxn];
int N,M;
int vis[maxn];
int in_d[maxn];
void input(){
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int s;
        cin>>s;
        vector<int> sta;
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=s;j++)
        {
            int ai;
            cin>>ai;
            vis[ai]=1;
            sta.push_back(ai);
        }
        for(int j=sta[0];j<=sta.back();j++)
        {
            if(vis[j])
                continue;
            for(auto v:sta)
            {
                if(G[j][v])
                    continue;
                G[j][v]=1;
                in_d[v]++;
            }
        }
    }
}
int bfs()
{
    int ans=0;
    queue<std::pair<int,int>> q;
    for(int u=1;u<=N;u++)
        if(!in_d[u]) q.push({u,1});
    while(!q.empty())
    {
        auto cur=q.front();
        q.pop();
        int u=cur.first;
        for(int v=1;v<=N;v++)
            if(G[u][v])
            {
                in_d[v]--;
                if(in_d[v]==0)
                {
                    q.push({v,cur.second+1});
                    ans=max(ans,cur.second+1);
                }
            }
    }
    return ans;
    
}
int main(){
    input();
    int ans=bfs();
    std::cout<<ans<<std::endl;
    return 0;
}