#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
const int maxn=500005;
using namespace std;
using ll=long long;
// ifstream ifs("input.txt");
// ofstream ofs("output.txt");
#define ifs cin
#define ofs cout
ll tree[maxn];
ll a[maxn];
ll add_tag[maxn],mul_tag[maxn];
ll mod;
ll get_mod(ll m)
{
    return m%mod;
}
int ls(int k){return k*2;}
int rs(int k){return k*2+1;}
void push_up(int k){
    tree[k]=tree[ls(k)]+tree[rs(k)];
    tree[k]%=mod;
}
void init(int k,int L,int R)
{
    add_tag[k]=0;
    mul_tag[k]=1;
    if(L==R) 
        tree[k]=a[L]%mod;
    else if(L<R)
    {
        int m=(L+R)/2;
        init(ls(k),L,m);
        init(rs(k),m+1,R);
        push_up(k);
    }
}
void f(int k,int L,int R,ll add,ll mul)
{
    tree[k]=get_mod(tree[k]*mul+(R-L+1)*add);
    mul_tag[k]= get_mod(mul_tag[k]*mul);
    add_tag[k]= get_mod(add_tag[k]*mul + add);
}
void push_down(int k,int L,int R)
{
    int m=(L+R)/2;
    f(ls(k),L,m,add_tag[k],mul_tag[k]);
    f(rs(k),m+1,R,add_tag[k],mul_tag[k]);
    add_tag[k]=0;
    mul_tag[k]=1;
}
void update(int k,int l,int r,int L,int R,int add,int mul)
{
    if(l>R || L>r) return;
    if(l<=L && r>=R ){
        f(k,L,R,add,mul);
        return;
    }   
    push_down(k,L,R);
    int mid=(L+R)/2;
    if(L<=mid) update(ls(k),l,r,L,mid,add,mul);
    if(R>mid) update(rs(k),l,r,mid+1,R,add,mul);
    push_up(k);
}
ll inquery(int k,int l,int r,int L,int R)
{
    if(l>R|| L>r)return 0;
    if(l<=L && r>=R) {
        return get_mod(tree[k]);
    }
    push_down(k,L,R);
    ll res=0;
    int mid=(L+R)/2;
    if(L<=mid) res+=inquery(ls(k),l,r,L,mid);
    if(R> mid) res+=inquery(rs(k),l,r,mid+1,R);
    return res%mod;
}
int main(){
    int n,m;
    ifs>>n>>m>>mod;
    for(int i=1;i<=n;i++) 
        ifs>>a[i];
    init(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int ins;
        ifs>>ins;
        if(ins==1)
        {
            int x,y,k;
            ifs>>x>>y>>k;
            update(1,x,y,1,n,0,k%mod);
        }
        else if(ins==2)
        {
            int x,y,k;
            ifs>>x>>y>>k;
            update(1,x,y,1,n,k%mod,1);
        }
        else if(ins==3)
        {
            int x,y;
            ifs>>x>>y;
            ofs<<inquery(1,x,y,1,n)<<endl;
        }
    }
    return 0;
}