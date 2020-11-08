#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
struct Pos
{
    int x=0,y=0;
    bool operator==(const Pos &p)const{
        return x==p.x&&y==p.y;
    }
    void print(){
        printf("(%d,%d)\n",x,y);
    }
};
const int maxn=305;
int vis[maxn][maxn];
int M,N;
char G[maxn][maxn];
Pos trans[128][2];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
Pos s,e;
void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            char ch=getchar();
            while(ch=='\n'||ch=='\r')
                ch=getchar();
            G[i][j]=ch;
            if(ch=='@')
                s={i,j};
            else if(ch=='=')
                e={i,j};
            else if(isalpha(ch))
            {
                if(trans[ch][0]==Pos{0,0})
                    trans[ch][0]={i,j};
                else 
                    trans[ch][1]={i,j};
            }
        }
}
Pos jmp(int x,int y)
{
    char ch=G[x][y];
    if(trans[ch][0]==Pos{x,y})
        return trans[ch][1];
    return trans[ch][0];
}
bool check(int x,int y)
{
    if(x<=0||y<=0||x>N||y>M)
        return false;
    if(G[x][y]=='#'||vis[x][y])
        return false;
    return true;
}
int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<pair<Pos,int>> q;
    q.push({s,0});
    vis[s.x][s.y]=1;
    while(!q.empty())
    {
        Pos cur=q.front().first;
        int cur_t=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=cur.x+dx[i],ny=cur.y+dy[i],nt=cur_t+1;
            if(!check(nx,ny))
                continue;
            else if(isalpha(G[nx][ny]))
            {
                // printf("(%d,%d)->",nx,ny);
                Pos npos=jmp(nx,ny);
                // npos.print();
                q.push({npos,nt});
                continue;
            }
            else if(G[nx][ny]=='=')
            {
                return nt;
            }
            q.push({Pos{nx,ny},nt});
            vis[nx][ny]=1;
        }
    }
    return -1;
}

int main(){
    input();
    std::cout<<bfs()<<endl;
    return 0;
}