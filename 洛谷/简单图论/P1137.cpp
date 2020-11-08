#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=100005;
vector<int> G[maxn];
int rd[maxn];
int ans[maxn];
int vis[maxn];
int N,M;
void input(){
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        rd[b]++;
    }
}

void bfs(){ 
    queue<pair<int,int>> q;
    for(int i=1;i<=N;i++)
    {
        if(!rd[i]){
             q.push({i,1});
             ans[i]=1;
        }
    }
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int u=cur.first,val=cur.second;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            rd[v]--;
            if(rd[v]==0)
            {
                q.push({v,val+1});
                ans[v]=max(ans[v],val+1);
            }
        }
    }
}   

int main(){
    input();
    bfs();
    for(int i=1;i<=N;i++)
        printf("%d\n",ans[i]);
    return 0;
}