#include <iostream>
#include <string>
const int maxn=10005;
/*
5 7 -1 6 -1 -1 3 -1 -1
8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
-1
*/
int sum[maxn];
//刘大法好+++
//草好吊.这辈子都写不出这么简洁的算法呜呜呜😭
void build(int p)
{
    int v;
    std::cin>>v;
    if(v==-1) return;
    sum[p]+=v;
    //刘的算法如此简洁--来自一个真正种了一棵树的小弱智。
    build(p-1);build(p+1);
}
using namespace std;
bool init(){
    int v;
    cin>>v;
    if(v==-1) return false;
    memset(sum,0,sizeof(sum));
    int pos=maxn/2;// 一开始我用了一个map<int,int>....
    sum[pos]=v;
    build(pos-1);build(pos+1);
    return true; //大刘你的书忘记加返回值了.
}
int main(){
    int kase=0;
    while(init())
    {
        int p=0;
        while(sum[p]==0) p++; 
        cout<<"Case "<<++kase<<":\n"<<sum[p++];
        while(sum[p]!=0)cout<<" "<<sum[p++];
        cout<<"\n\n";
    }
    return 0;
}