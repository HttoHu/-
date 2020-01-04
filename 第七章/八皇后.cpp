#include <iostream>
#include <string>
using namespace std;
int vis[100];
int n;
void search(int cur){
    if(n==cur){
        for(int i=0;i<n;i++){
            cout<<"("<<i<<","<<vis[i]<<")";
        }
        cout<<"\n";
    }
    else
    {
        for(int i=0;i<n;i++){
            bool ok=true;
            vis[cur]=i;
            for(int j=0;j<cur;j++){
                if(vis[cur]==vis[j]||j+vis[j]==cur+vis[cur]||j-vis[j]==cur-vis[cur]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                search(cur+1);
            }
        }
    }
}
int main(){
    n=4;
    search(0);
    return 0;
}