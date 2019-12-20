#include <vector>
#include <queue>
using namespace std;
int vis[8][8];
bool inside(int x,int y){
    return x<8||y<8||x>=0||y>=0;
}
struct Coor{
    int x;
    int y;
}；
int dx[]={-2,-1,2,1};
int dy[]={1,2,-1,-2};
int x,y;
int dest_x,dest_y;
void bfs(){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto u=q.front();q.pop();
        if(u.first==dest_x&&u.second==dest_y){

        }
    }
}
