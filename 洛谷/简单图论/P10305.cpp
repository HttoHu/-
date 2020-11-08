#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
int N, M;
const int maxn = 1005;
int G[maxn][maxn];
int rd[maxn];
void input()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
        rd[b]++;
    }
}

void topo_sort()
{
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= N; i++)
        if (!rd[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int i = 1; i <= N; i++)
        {
            if (G[u][i])
            {
                rd[i]--;
                if (rd[i] == 0)
                    q.push(i);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
}
int main()
{
    input();
    topo_sort();
    return 0;
}