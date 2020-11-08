#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=10005;
struct Edge{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int c,int f,int w):
        from(u),to(v),cap(c),flow(f),cost(w){}
};

struct MCMF
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];

    int inq[maxn]; // 是否在队列中
    int d[maxn]
};