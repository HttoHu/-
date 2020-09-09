#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
3
2 5
0 
0 1 0 0 0
0 0 0 1 0
4 6
1
0 1 1 0 0 0
0 0 1 0 1 1
0 1 1 1 1 0
0 1 1 1 0 0
2 2
0
0 1
1 0
*/
struct Coor
{
    int x;
    int y;
    Coor(){}
    Coor(int a,int b):x(a),y(b){}
};
int m,n;
const int maxn=20+5;
int mmap[maxn][maxn];
int vis[maxn][maxn];
Coor back_path[maxn][maxn];
int turbo;

bool inside(int x,int y){
    return x>=0&&y>=0&&x<m&&y<n;
}
int count_steps(){
    int ret=2;
    Coor cur_node(m-1,n-1);
    while (cur_node.x!=0||cur_node.y!=0)
    {
        ret++;
        cur_node=back_path[cur_node.x][cur_node.y];
    }
    return ret;
    
}
bool bfs(){
    memset(vis,0,sizeof(vis));
    queue<Coor> q;
    q.push(Coor(0,0));
    while(!q.empty()){
        auto u=q.front();q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if((i==0&&j==0)||((abs(i)+abs(j))==2)){
                    continue;
                }
                Coor tmp(u.x+i,u.y+j);
                int turbo_mod=vis[u.x][u.y]+ mmap[u.x][u.y];
                if(!inside(tmp.x,tmp.y)|| turbo_mod-10>turbo || vis[tmp.x][tmp.y]){
                    continue;
                }
                if(turbo_mod==0){
                    turbo_mod+=10;
                }
                q.push(tmp);
                vis[tmp.x][tmp.y]=turbo_mod;
                back_path[tmp.x][tmp.y]=u;
                if(tmp.x==m-1&&tmp.y==n-1)
                    return true;
            }
        }
    }
    return false;
}
void input(){
    memset(mmap,0,sizeof(mmap));
    cin>>m>>n;
    cin>>turbo;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mmap[j][i];
        }
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        input();
        if(!bfs()){
            cout<<"-1\n";
        }
        else
            cout<<count_steps()<<endl;
    }
    return 0;
}