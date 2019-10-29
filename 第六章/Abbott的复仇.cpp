// UVa816 Abbott's Revenge
/*
SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
*/
#include <queue>
#include <iostream>
#include <list>
#include <bitset>
using DirSet = std::bitset<3>;
enum DirMod
{
	N=0,E,S,W

};
enum TurnMod
{
	L=0,R,F
};
struct Node
{
	DirSet Tinfo[4];
	bool inside(DirMod dir) {
		bool ret=true;
		for (int i = 0; i < 4; i++)
			ret =ret && Tinfo[dir][i];
		return ret;
	}
};
Node maze[10][10];
struct Coor {
	int x;
	int y;
	bool no_result() { return x < 0 || y < 0; }
};
Node get_node(Coor c)
{
	return maze[c.x][c.y];
}
bool turn_able(Node cur_pos, DirMod dm, TurnMod tm)
{
	return cur_pos.Tinfo[dm][tm];
}
bool range_over(int x, int y)
{
	return x > 9 || x < 0 || y>9 || y < 0;
}
Coor walk(int x, int y, DirMod dm, TurnMod tm)
{
	auto curr = maze[x][y];
	if (!turn_able(curr, dm, tm))
		return { -1,-1 };
	switch (dm)
	{
	case N:
		switch (tm)
		{
		case L:
			if (range_over(x, y - 1))
				return { -1,-1 };
			return { x,y - 1 };
		case R:
			if (range_over(x, y + 1))
				return { -1,-1 };
			return { x,y + 1 };
		case F:
			if (range_over(x-1, y))
				return { -1,-1 };
			return { x-1,y };
		}
	case E:
		switch (tm)
		{
		case L:
			if (range_over(x-1, y))
				return { -1,-1 };
			return { x-1,y};
		case R:
			if (range_over(x+1, y))
				return { -1,-1 };
			return { x+1,y};
		case F:
			if (range_over(x, y+1))
				return { -1,-1 };
			return { x,y+1 };
		}
	case S:
		switch (tm)
		{
		case L:
			if (range_over(x, y +1))
				return { -1,-1 };
			return { x,y + 1 };
		case R:
			if (range_over(x, y - 1))
				return { -1,-1 };
			return { x,y - 1 };
		case F:
			if (range_over(x + 1, y))
				return { -1,-1 };
			return { x + 1,y };
		}
	case W:
		switch (tm)
		{
		case L:
			if (range_over(x + 1, y))
				return { -1,-1 };
			return { x + 1,y };
		case R:
			if (range_over(x -1 , y))
				return { -1,-1 };
			return { x - 1,y };
		case F:
			if (range_over(x, y - 1))
				return { -1,-1 };
			return { x,y - 1 };
		}
	default:
		break;
	}
}
int x0, y0,dir0;
int x1, y1;
Coor solve()
{
	std::queue<Coor> q;
	q.push({ x0,y0 });
	DirMod this_dir = (DirMod)dir0;
	auto first = q.front();
	while (get_node(first).inside(this_dir)) {
		
	}
}