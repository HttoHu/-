#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdio>
using namespace std;
int N,S,T;
const int maxn=100005;
long long a[maxn];
long long s[maxn];
bool check(int x)
{  
    for(int i=1;i<=N;i++)
        s[i]=s[i-1]+(a[i]-x);
    deque<int> q;
    for(int i=S,p=0;i<=N;i++,p++)
    {
        while(!q.empty()&& s[q.back()] > s[p])
            q.pop_back();
        q.push_back(p);
        while(!q.empty() && q.front() < i-T)
            q.pop_front();
        if (s[i]-s[q.front()]>=0)  
            return true;
    }
    return false;
}
void input(){
    cin>>N>>S>>T;
    for(int i=1;i<=N;i++)
    {    
        cin>>a[i];
        a[i]*=10000;
    }
}
int main(){
    memset(s,0,sizeof(s));
    int l=-0x3f3f3f3f,r=0x3f3f3f3f;
    input();
    while(r-l > 1)
    {
        int mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else 
            r=mid;
    }
    printf("%.3lf",l/10000.0);
    return 0;
}