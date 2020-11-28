#include <iostream>
#include <vector>
using namespace std;
const int maxn=100005;
using ll=long long;
ll tree[maxn];
ll a[maxn];
ll tag[maxn];
int rs(int k){return 2*k+1;}
int ls(int k){return 2*k;}
void push_up(int k){
    tree[k]=tree[rs(k)]+tree[ls(k)];
}
void f(int k,int L,int R,int v)
{
    tag[k]+=v;
    tree[k]+=(R-L+1)*v;
}
void push_down(int k,int L,int R)
{
    int m=(L+R)/2;
    f(ls(k),L,m,tag[k]);
    f(rs(k),m+1,R,tag[k]);
    tag[k]=0;    
}

void init(int k,int L,int R)
{
    tag[k]=0;
    if(L==R) tree[k]=a[L];
    else 
    {
        int m=(L+R)/2;
        init(ls(k),L,m);
        init(rs(k),m+1,R);
        push_up(k);
    }
}
ll query(int k,int l,int r,int L,int R)
{
    if(l>R || r<L) return 0;
    if(l<=L && r>=R) return tree[k];
    push_down(k,L,R);
    int m=(L+R)/2;
    ll res=0;
    if(l <= m) res+=query(ls(k),l,r,L,m);
    if(r > m) res+=query(rs(k),l,r,m+1,R);
    return res; 
}
void change(int k,int l,int r,int L,int R,int v)
{
    if(l>R || r<L) return;
    if(l<=L && r>=R){
        f(k,L,R,v);
        return;
    }
    push_down(k,L,R);
    int m=(L+R)/2;
    if(l<=m) change(ls(k),l,r,L,m,v);
    if(r>m) change(rs(k),l,r,m+1,R,v);
    push_up(k);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    init(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x,y,k;
            cin>>x>>y>>k;
            change(1,x,y,1,n,k);
        }
        else{
            int x,y;
            cin>>x>>y;
            ll res=query(1,x,y,1,n);
            cout<<res<<endl;
        }
    }
    return 0;
}