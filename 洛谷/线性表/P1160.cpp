#include <iostream>
#include <cstdio>
#include <cstring>
const int maxn = 100005;
int nxt[maxn];
int prv[maxn];
int vis[maxn];
int cnt = 1;
int main()
{
    int N;
    memset(nxt, -1, sizeof(nxt));
    memset(prv, -1, sizeof(prv));
    scanf("%d", &N);
    prv[1] = 0;
    nxt[0] = 1;
    for (int i = 2; i <= N; i++)
    {
        int k, p;
        scanf("%d%d", &k, &p);
        int next = nxt[k];
        int pre = prv[k];
        if (p == 0)
        {
            int old_pre = prv[k];
            nxt[i] = k;
            prv[k] = i;
            if (old_pre != -1)
            {
                nxt[old_pre] = i;
                prv[i] = old_pre;
            }
        }
        else if (p == 1)
        {
            int old_next = nxt[k];
            nxt[k] = i;
            prv[i] = k;
            if (old_next != -1)
            {
                prv[old_next] = i;
                nxt[i] = old_next;
            }
        }
    }
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int k;
        scanf("%d", &k);
        vis[k] = 1;
    }
    int next = nxt[0];
    while (next != -1)
    {
        if (vis[next])
        {
            next = nxt[next];
            continue;
        }
        else
        {
            printf("%d", next);
            next = nxt[next];
            printf("%c", " \n"[next == -1]);
        }
    }
    return 0;
}