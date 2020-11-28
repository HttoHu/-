#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
const int maxn=5000005;
using ll=long long;
int ls(int k){return 2*k;}
int rs(int k){return 2*k+1;}
ifstream ifs("input.txt");
ll tree[maxn];
struct unit
{
    ll value;
    ll idx;
    bool operator<(const unit&u)const{
        if(value==u.value)
            return idx>u.idx;
        return value > u.value;
    }
};
unit f[maxn];
void push_up(int k){tree[k]=tree[ls(k)]+tree[rs(k)];}
void add(int k,int pos,int L,int R,ll v)
{
    // printf("%d %d %d %d\n",k,pos,L,R);
    if(pos<L || pos>R) return;
    if(L==R){
        tree[k]+=v;
        return;
    }
    int mid=(L+R)/2;
    if(pos <=mid) add(ls(k),pos,L,mid,v);
    if(pos > mid) add(rs(k),pos,mid+1,R,v);
    push_up(k);
}
ll query(int k,int l,int r,int L,int R)
{
    if(l>R || L>r) return 0;
    if(l<=L && r>=R) return tree[k];
    int mid=(L+R)/2;
    ll res=0;
    if(L<=mid) res+=query(ls(k),l,r,L,mid);
    if(R>mid) res+=query(rs(k),l,r,mid+1,R);
    return res;
}
int main(){
    memset(tree,0,sizeof(tree));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i].value;
        f[i].idx=i;
    }
    sort(f+1,f+1+n);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        add(1,f[i].idx,1,n,1);
        res+=query(1,1,f[i].idx-1,1,n);
    }
    cout<<res;
    return 0;
}