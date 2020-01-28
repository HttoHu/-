#include <iostream>
using namespace std;
int cross[22][22]={0};
int dest;
int vis[22]={0};
int path[22];
void input(){
    cin>>dest;
    int x,y;
    while(true){
        cin>>x>>y;
        if(x==0&&y==0)
            break;
        cross[x][y]=1;
        cross[y][x]=1;
    }
}
void solve(int cur,int s){
    if(cur==dest){
        std::cout<<"1 ";
        for(int i=1;i<s;i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=1;i<22;i++){
            if(cross[cur][i]&&!vis[i])
            {
                vis[i]=1;
                path[s]=i;
                solve(i,s+1);
                vis[i]=0;
            }
        }
    }
}

int main(){
    path[1]=1;
    vis[1]=1;
    input();
    std::cout<<"CASE 0:\n------------------------------\n";
    solve(1,1);
    return 0;
}