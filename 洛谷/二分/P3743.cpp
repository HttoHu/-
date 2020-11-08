#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const long double eps=0.00001;
long long n,p;
const int maxn=100005;
struct Device
{
    Device(){};
    Device(int x,int y):v(x),c(y){
        t=(long double)c/v;
    }
    bool operator<(const Device& dev)const{
        return t<dev.t;
    }
    int v;
    int c;
    long double t;
};
Device arr[maxn];

bool input(){
    cin>>n>>p;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i]=Device(a,b);
        sum+=a;
    }
    sort(arr+1,arr+n+1);
    return p>=sum;
}

bool check(long double x)
{
    long double r=x;
    for(int i=1;i<=n;i++)
    {
        if(arr[i].t >= x)
            return true;
        long double c=arr[i].c;
        long double v=arr[i].v;
        long double mt=(c+p*r)/v;
        if(mt<x)
            return false;
        long double t1=(v*x-c)/p;
        r-=t1;
        if(r<0)
            return false;
    }
    return true;
}

int main(){
    if(input())
    {
        cout<<-1<<endl;
        return 0;
    }
    long double L=eps,R=5000000005.0;
    while(abs(R-L)>eps)
    {
        long double m=(L+R)/(long double)(2);
        if(check(m))
            L=m;
        else 
            R=m;
    }
    printf("%Lf\n",L);
    return 0;
}