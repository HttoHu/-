#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <stdio.h>
/*
	水平太差，自己写不出来，仔细看了代码后模仿了,还炸了好几次，然后再看代码，无限循环😭
*/
// node 表示一个状态, 在r,c位置的朝向
struct Node
{
	Node() {}
	Node(int _r, int _c, int _dir) :r(_r), c(_c), dir(_dir) {}
	int r = 0;
	int c = 0;
	int dir = 0;
};
const char* dirs = "NESW";
const char* turns = "FLR";
int dc[] = { 0,1,0,-1 };
int dr[] = { -1,0,1,0 };
int get_dir(char ch) {
	return strchr(dirs, ch) - dirs;
}
int get_turns(char ch)
{
	return strchr(turns, ch) - turns;
}
int path[10][10][4];
Node move_a[10][10][4];
int edge[10][10][4][3];
int r0, c0, r1, c1, r2, c2, dir;

bool input()
{
	std::string program_name;
	char first_dir;
	std::cin >> program_name;
	std::cin >> r0 >> c0 >> first_dir >> r2 >> c2;
	r1 = r0 + dr[dir];
	c1 = c0 + dc[dir];

	dir = get_dir(first_dir);
	while (true)
	{
		int r, c;
		std::cin >> r;
		if (r == 0)
			break;
		std::cin >> c;
		std::string word;
		while (std::cin >> word && word != "*")
		{
			int _dir = get_dir(word[0]);
			for (int i = 1; i < word.size(); i++)
			{
				edge[r][c][_dir][get_turns(word[i])] = 1;
			}
		}
	}
	return true;

}
bool inside(int r, int c)
{
	return r <= 9 && r >= 1 && c <= 9 && c >= 1;
}
Node walk(Node n, int w)
{
	int dir = n.dir;
	if (w == 1)
		// 逻辑上是(dir-1)%4，但是防止负数导致模运算出现未定义行为,我们加三
		dir = (dir + 3) % 4;
	if (w == 2)
		dir = (dir + 1) % 4;
	return Node(n.r + dr[dir], n.c + dc[dir], dir);
}
void print_ans(Node u)
{
	std::vector<Node> nodes;
	nodes.push_back(u);
	while (path[u.r][u.c][u.dir] != 0)
	{
		u = move_a[u.r][u.c][u.dir];
		nodes.push_back(u);
	}
	nodes.push_back(Node(r0, c0, dir));
	for (int i = nodes.size()-1; i >= 0; i--)
	{
		std::cout << "(" << nodes[i].r << "," << nodes[i].c << ")";
	}
}
void solve()
{
	std::queue<Node> qu;
	memset(path, -1, sizeof(path));
	Node u(r1, c1, dir);
	path[u.r][u.c][u.dir] = 0;
	qu.push(u);

	while (!qu.empty())
	{
		Node tmp = qu.front();
		qu.pop();
		if (tmp.r == r2 && tmp.c == c2)
		{
			print_ans(tmp);
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			Node tmp2 = walk(tmp, i);
			if (edge[tmp.r][tmp.c][tmp.dir][i] && inside(tmp2.r, tmp2.c) && path[tmp2.r][tmp2.c][tmp2.dir] < 0)
			{
				path[tmp2.r][tmp2.c][tmp2.dir] = path[tmp.r][tmp.c][tmp.dir] + 1;
				move_a[tmp2.r][tmp2.c][tmp2.dir] = tmp;
				qu.push(tmp2);
			}
		}
	}
	std::cout << " No solution found!";
}
int main()
{
	while (true)
	{
		input();
		solve();
	}
	return 0;
}