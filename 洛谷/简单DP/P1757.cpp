#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int M, N;

struct Bag
{
    int w, v, team;
    bool operator<(const Bag &b) const
    {
        return team < b.team;
    }
} bags[1005];
int dp[1005][1005];
int main()
{
    cin >> M >> N;
    for (int i = 1; i <= N; i++)
        cin >> bags[i].w >> bags[i].v >> bags[i].team;
    sort(bags+1, bags + N+1);
    for (int i = 1; i <= N; i++)
    {
        int k = bags[i].team;
        for (int j = M; j >= 0; j--)
        {
            if (j < bags[i].w)
                dp[j][k] = max(dp[j][k], dp[j][k - 1]);
            else
                dp[j][k] = max(dp[j][k], dp[j - bags[i].w][k - 1]+bags[i].v);
        }
    }
    std::cout<<dp[M][bags[N].team];
}