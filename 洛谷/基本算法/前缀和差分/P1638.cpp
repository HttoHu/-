#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int maxn=1000005;
int a[maxn];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    map<int,int> s;
    int ms=1,me=0;
    int ans_x=1,ans_y=n;
    while(ms<=n)
    {
        while(me+1<=n && s.size()!=m)
        {
            me++;
            if(s.count(a[me]))
                s[a[me]]++;
            else
                s.insert({a[me],1});
        }
        if(s.size()!=m)
            break;
        if(me-ms < ans_y-ans_x)
        {ans_x=ms,ans_y=me;}
        if(s[a[ms]]==1)
            s.erase(a[ms]);
        else 
            s[a[ms]]--;
        ms++;
    }
    cout<<ans_x<<" "<<ans_y<<endl;
    return 0;
}