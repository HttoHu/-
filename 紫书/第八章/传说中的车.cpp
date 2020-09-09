#define MY_VERSION
#define MY_GEJLJGLREKJ
#ifdef MY_VERSION
#include <iostream>
#include <vector>
/*
1 1
5 7
2 2
3 3
6 5
7 4
8 6
4 8
*/
using namespace std;
vector<int> x_results;
vector<int> y_results;
int n = 0;
/*
8
1 1 2 2
5 7 8 8 
2 2 5 5
2 2 5 5 
6 3 8 6
6 3 8 5
6 3 8 8
3 6 7 8
*/
struct Rectangle
{
	Rectangle(int a, int b, int c, int d) :x1(a), my_y1(b), x2(c), y2(d) {}
	int x1;
	int my_y1;
	int x2;
	int y2;
};
vector<Rectangle> recs;
void input()
{
	std::cin >> n;
	x_results.resize(n,-1);
	y_results.resize(n,-1);
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		recs.push_back(Rectangle(a, b, c, d));
	}
}
bool solve()
{
	for (int i = 0; i < n; i++)
	{
		int minb=n+1;
		int rook = -1;
		int rooky = -1;
		int minb2 = n + 1;
		for (int j = 0; j < n; j++)
		{
			// find the range which is the begin pos is min and suit to put the pos into it.
			if (x_results[j] < 0 && recs[j].x1<=i+1&&recs[j].x2 < minb)
			{
				minb = recs[j].x2;
				rook = j;
			}
			if (y_results[j] < 0 && recs[j].my_y1 <= i + 1 && recs[j].y2 < minb2)
			{
				minb2 = recs[j].y2;
				rooky = j;
			}
		}
		if (rook == -1||rooky==-1)
			return false;
		x_results[rook] = i+1;
		y_results[rooky] = i + 1;
	}
	return true;
}
int main()
{
	input();
	if(!solve())
	{ 
		cout<<"IMPOSSIBLE";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << x_results[i] << " " << y_results[i] << std::endl;
	}
	return 0;
}
#else
// UVa11134 Fabled Rooks
// Rujia Liu
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;

// solve 1-D problem: find c so that a[i] <= c[i] <= b[i] (0 <= i < n)
bool solve(int* a, int* b, int* c, int n) {
	fill(c, c + n, -1);
	for (int col = 1; col <= n; col++) {
		// find a rook with smalleset b that is not yet assigned
		int rook = -1, minb = n + 1;
		for (int i = 0; i < n; i++)
			if (c[i] < 0 && b[i] < minb && col >= a[i]) { rook = i; minb = b[i]; }
		if (rook < 0 || col > minb) return false;
		c[rook] = col;
	}
	return true;
}

const int maxn = 5000 + 5;
int n, x1[maxn], my_y1[maxn], x2[maxn], y2[maxn], x[maxn], y[maxn];

int main() {
	while (scanf_s("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++)
			scanf_s("%d%d%d%d", &x1[i], &my_y1[i], &x2[i], &y2[i]);
		if (solve(x1, x2, x, n) && solve(my_y1, y2, y, n))
			for (int i = 0; i < n; i++) printf("%d %d\n", x[i], y[i]);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

#endif