// Cutting Sticks
#include <iostream>
#include <algorithm>
/*
100
3
25 50 75
10
4
4 5 7 8
0
*/
using namespace std;
int L;
const int maxn = 55;
int cp[maxn];// cutting point;
int dp[maxn][maxn], vis[maxn][maxn];
int search(int i, int j) {
	if (i >= j-1) return 0;
	if (vis[i][j])
		return dp[i][j];
	vis[i][j] = 1;
	int &ans = dp[i][j];
	ans = 0x3f3f3f3f;
	for (int k = i; k <= j - 1; k++)
		ans = min(ans, search(i, k) + search(k, j) + cp[j] - cp[i]);
	return ans;
}
int main() {
	while (cin >> L&&L)
	{
		memset(vis, 0, sizeof(dp));
		int n;
		cin >> n;
		cp[0] = 0;
		cp[n + 1] = L;
		for (int i = 1; i <= n; i++)
			cin >> cp[i];
		cout << "The minimum cutting is:" << search(0, n + 1) << endl;
	}
	while (1)cin.get();
	return 0;
}