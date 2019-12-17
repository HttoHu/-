/*
给一个n个点条边(2≤n≤100000，1≤m≤200000)的无向图，每条边上都涂有一中颜色。
求从结点1到结点"的一条路径，使得经过的边数尽量少，在此前提下，经过边
的颜色序列的字典序最小。一对结点间可能有多条边，一条边可能连接两个相同结点。输
如保证结点1可以达到结点n。颜色为1-10^9的整数。
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
/*
4 6
1 2 1
1 3 2
3 4 3
2 3 1
2 4 4
3 1 1
*/
const int maxn=100000+5;
const int INF=100000000;

struct Edge{
    int u,v,c;
    Edge(int _u=0,int _v=0,int _c=0):u(_u),v(_v),c(_c){}
};

vector<Edge> edges;
vector<int> G[maxn];

void AddEdge(int u,int v,int c){
    edges.push_back(Edge(u,v,c));
    int idx=edges.size()-1;
    G[u].push_back(idx);
}

int n,vis[maxn];
int d[maxn];
vector<int> ans;
void rev_bfs(){
    memset(vis,0,sizeof(vis));
    d[n-1]=0;
    vis[n-1]=true;

    queue<int> q;
    q.push(n-1);
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int i=0;i<G[v].size();i++){
            int e=G[v][i];// v于那些节点连在一起
            int u=edges[e].v; //获得那个连在一起的节点编号。
            if(!vis[u]){//该节点还没有走到过
                vis[u]=true; //标记为走到
                d[u]=d[v]+1; 
                q.push(u);
            }
        }
    }
}
void bfs(){
    memset(vis,0,sizeof(vis));
    vis[0]=true;
    ans.clear();

    vector<int> next;//因为需要计算最小的颜色，所以只能用vector来bfs
    next.push_back(0);
    for(int i=0;i<d[0];i++){//d[0]是0节点到最后一个节点的最小距离
        int min_color=INF;
        for(int j=0;j<next.size();j++){
            int u=next[j];
            for(int k=0;k<G[u].size();k++){
                int e=G[u][k];
                int v=edges[e].v;
                if(d[u]==d[v]+1)
                    min_color=min(min_color,edges[e].c);
            }
        }
        ans.push_back(min_color);

        vector<int> next2;
        for(int j=0; j<next.size();j++){
            int u=next[j];
            for(int k=0;k<G[u].size();k++){
                int e=G[u][k];
                int v=edges[e].v;
                if(d[u]==d[v]+1&&!vis[v]&&edges[e].c==min_color){
                    vis[v]=true;
                    next2.push_back(v);
                }
            }
        }
        next=next2;
    }
    printf("%d\n",ans.size());
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++)printf(" %d",ans[i]);
    printf("\n");
}
int main(){
    int u,v,c,m;
    while(scanf("%d%d",&n,&m)==2){
        edges.size();
        for(int i=0;i<n;i++) G[i].clear();
        while(m--){
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u-1,v-1,c);
            AddEdge(v-1,u-1,c);
        }
        rev_bfs();
        bfs();
    }
    return 0;
}