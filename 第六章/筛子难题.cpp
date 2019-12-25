#include <iostream>
#include <vector>
#include <string>
#include <queue>
int tor[7][7];
/*
3 3 1 2 5 1
-1 2 4
5 5 6
6 -1 -1

4 7 2 6 3 6
6 4 6 0 2 6 4
1 2 -1 5 3 6 1
5 3 4 5 6 4 2
4 1 2 0 3 -1 6

OUTPUT:
(1 2) (2 2) (2 3) (3 3) (3 2 )(3 1) (2 1) (1 1) (1 2)
*/
using namespace std;
/*
0. Upper    a 
1. Left <   b 
2. Right >  c 
3. Forwad ^ d 
4. Back v   e 
5. Lower    f 
*/
enum
{
    Upper = 0,
    Left = 1,
    Right = 2,
    Forward = 3,
    Back = 4,
    Lower = 5
};
struct Pos
{
    int r;
    int c;
    int above,face;
    Pos(int a, int b, int c,int d) : r(a), c(b), above(c),face(d) {}
    Pos(){}
    void show(){
        cout<<"("<<r+1<<","<<c+1<<","<<above<<")";
    }
};
const int maxn = 100;
int dr[4] = {-1, 0, 1, 0}; // ^ > V <
int dc[4] = {0, 1, 0, -1};
int dice_map[maxn][maxn];
bool vis[maxn][maxn][7][7] = {false};
int width, height;
int r0, c0;
int cur_up, cur_back;
Pos d[maxn][maxn][7][7];
void input()
{
    cin >> width >> height >> r0 >> c0 >> cur_up >> cur_back;
    r0--;
    c0--;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
            cin >> dice_map[i][j];
    }
}
// ^ > V <
/*
0. Upper    a 
1. Left <   b 
2. Right >  c 
3. Forwad ^ d 
4. Back v   e 
5. Lower    f 
*/
void walk(int i, Pos &p)
{
    int tmp=0;
    switch (i)
    {
    case 0:
        tmp=7-p.above;
        p.above=p.face;
        p.face=tmp;
        return;
    case 1:
        p.above=7-tor[p.above][p.face];
        return;
    case 2:
        tmp=7-p.face;
        p.face=p.above;p.
        above=tmp;
        return;
    case 3:
        p.above=tor[p.above][p.face];
        return ;
    }
    cout<<"DAMN";
}
int last_above,last_face;
bool bfs()
{
    std::queue<Pos> q;
    q.push(Pos(r0, c0 , cur_up,cur_back));
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Pos v(u.r+dr[i],u.c+dc[i],u.above,u.face);
            if(v.r<0||v.c<0||v.r>=width||v.c>=height) continue;
            if(dice_map[v.r][v.c]!=-1 && u.above!=dice_map[v.r][v.c]){
                continue;
            }
  
            if(v.r==r0&&v.c==c0){
                last_above=v.above;
                last_face=v.face;
                d[v.r][v.c][last_above][last_face] = u;
                return true;
            }
            walk(i,v);
            if(vis[v.r][v.c][v.above][v.face])
                continue;
            d[v.r][v.c][v.above][v.face] = u;
            vis[v.r][v.c][v.above][v.face] = true;
            q.push(v);
        }
    }
    return false;
}
void show_ans()
{
    vector<pair<int,int>> tmp;
    Pos last=d[r0][c0][last_above][last_face];
    tmp.push_back({r0,c0});
    while (true)
    {
        tmp.push_back({last.r,last.c});
        last = d[last.r][last.c][last.above][last.face];
        if (last.r == r0 && last.c == c0)
            break;
    }
    tmp.push_back({last.r,last.c});
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        cout << "(" << tmp[i].first + 1 << "," << tmp[i].second + 1 << ")"
             << " ";
    }
}
int main()
{
    tor[1][2] = 3;
    tor[1][3] = 5;
    tor[1][5] = 4;
    tor[1][4] = 2;
    tor[2][1] = 4;
    tor[2][3] = 1;
    tor[2][4] = 6;
    tor[2][6] = 3;
    tor[3][6] = 5;
    tor[3][5] = 1;
    tor[3][1] = 2;
    tor[3][2] = 6;
    tor[4][6] = 2;
    tor[4][2] = 1;
    tor[4][1] = 5;
    tor[4][5] = 6;
    tor[5][6] = 4;
    tor[5][4] = 1;
    tor[5][1] = 3;
    tor[5][3] = 6;
    tor[6][4] = 5;
    tor[6][5] = 3;
    tor[6][3] = 2;
    tor[6][2] = 4;
    input();
    if (bfs())
    {
        show_ans();
    }
    else
    {
        cout << "impossible";
    }
    return 0;
}