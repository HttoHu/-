#include <cstdio>
#include <cstring>
#include <queue>

struct Node {
	int v[3], dist;
	bool operator<(const Node& rhs)const {
		return dist > rhs.dist;
	}
};
const int maxn = 205;
int vis[maxn][maxn], cap[3], ans[maxn];
void update_ans(const Node& u) {
	for (int i = 0; i < 3; i++)
	{
		int d = u.v[i];
		if (ans[d] < 0 || u.dist < ans[d])
			ans[d] = u.dist;
	}
}

void solve(int a, int b,int c, int d)
{
	cap[0] = a; cap[1] = b; cap[2] = c;
	memset(vis, 0, sizeof(vis));
	memset(ans, -1, sizeof(ans));
	std::priority_queue<Node> q;
	Node start;
	start.dist = 0;
	start.v[0] = 0;
}