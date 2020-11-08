#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
const int maxn = 100050;
using namespace std;
vector<int> G[maxn];
int N, M;
int d[maxn];
void damn(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        d[u] = max(d[u], d[v]);
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        d[i] = i;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    for (int j = 0; j < 100; j++)
        for (int i = 1; i <= N; i++)
            damn(i);
    for (int i = 1; i <= N; i++)
        printf("%d%c", d[i], " \n"[i == N]);
    return 0;
}