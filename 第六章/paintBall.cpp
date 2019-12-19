#include <iostream>
#include <vector>
/*
我写的是错的额，我页不知道为什么。我知道它可以从北边出去，但是为什么。。。。你试试下面的输入，
显示无解....
3
500 500 499
0 0 999
1000 1000 200
*/
using namespace std;
const int maxn=1000;
int warface[maxn+1][maxn+1];
void paint(int a,int b,int c){
    // hight->height.
    int max_hight=b+c;
    int min_hight=b-c;
    int max_width=a+c;
    int min_width=a-c;
    if(max_hight>maxn){max_hight=maxn;}
    if(min_hight<0){min_hight=0;}
    if(max_width>maxn){max_width=maxn;}
    if(min_width<0){min_width=0;}
    for(int i=min_width;i<=max_width;i++)
    {
        for(int j=min_hight;j<=max_hight;j++){
            if(sqrt((a-i)*(a-i)+(b-j)*(b-j))<=c){
                warface[i][j]=-1;
            }
        }
    }
}
void dfs(int x,int y){
    if(x<0||x>maxn||y<0||y>maxn) return;
    if(!warface[x][y]){
        warface[x][y]=1;
    }
    else return;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        if(i!=x&&j!=y){
            dfs(i+x,j+y);
        }
    }
}
void print_war_face()
{
    for(int i=0;i<=6;i++){
        for(int j=0;j<=6;j++){
            std::cout<<warface[i][j];
        }
        cout<<endl;
    }
}
int main(){
    memset(warface,0,sizeof(warface));
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        paint(a,b,c);
    }
    int x,y,ok=0;
    for(int i=maxn;i>=0;i--){
        if(warface[0][i])
            continue;
        dfs(0,i);
        for(int j=maxn;j>=0;j--){
            if(warface[maxn][j]==1){
                x=i;y=j;
                ok=1;
                break;
            }
        }
        if(ok)break;
    }
    if(ok){
        cout<<"POSSIBLE: "<<x<<" "<<y;
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
    return 0;
}