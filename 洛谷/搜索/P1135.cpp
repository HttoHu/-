#include <iostream>
#include <queue>
using namespace std;
int N,A,B;
const int maxn=205;
int arr[maxn];
int d[maxn];
int vis[maxn];
void input(){
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
}

int bfs(){
    if(A==B)
        return 0;
    queue<int> q;
    q.push(A);
    vis[A]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        int np1=cur+arr[cur];
        if(!vis[np1]&&np1>=1&&np1<=N)
        {
            if(np1==B)
                return d[cur]+1;
            q.push(np1);
            d[np1]=d[cur]+1;
            vis[np1]=1;
        }
        int np2=cur-arr[cur];
        if(!vis[np2]&&np2>=1&&np2<=N)
        {
            if(np2==B)
                return d[cur]+1;
            q.push(np2);
            d[np2]=d[cur]+1;
            vis[np2]=1;
        }
    }
    return -1;
}
int main(){
    input();
    cout<<bfs()<<endl;
    return 0;
}