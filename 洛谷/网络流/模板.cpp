#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
/*
    计算每条边的残量（流量之差），形成一个增广路，
*/
const int maxn=10005;
using namespace std;
struct Edge{
    int from,to,cap,flow;
    Edge(int a,int b,int c,int d):from(a),to(b),cap(c),flow(d){}
};
struct EdmonsKarp
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn]; // 起点到i的可修改量
    int p[maxn]; // 最短路入弧编号
    void init(int n){
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void add_edge(int from,int to,int cap){
        edges.push_back({from,to,cap,0});
        edges.push_back({to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1); 
    }

    long long max_flow(int s,int t)
    {
        long long flow=0;
        while(1){
            memset(a,0,sizeof(a));
            queue<int> q;
            q.push(s);
            a[s]=0x3f3f3f3f;
            while(!q.empty()){
                int x=q.front();q.pop();
                for(int i=0;i<G[x].size();i++)
                {
                    Edge &e=edges[G[x][i]];
                    if(!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        q.push(e.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};
int main(){
    EdmonsKarp ek;
    int m,s,t;
    cin>>ek.n>>m>>s>>t;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ek.add_edge(a,b,c);
    }
    std::cout<<ek.max_flow(s,t);
    return 0;
}