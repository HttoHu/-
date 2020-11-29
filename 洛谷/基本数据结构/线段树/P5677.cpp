#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=500005;
int n,m;
int lowbit(int x){
    return x&(-x);
}

struct BIT
{
    BIT(){
        memset(bit,0,sizeof(bit));
    }
    int bit[maxn];
    void add(int p,int x){
        while(p<=n)
        {
            bit[p]+=x;
            p+=lowbit(p);
        }
    }
    int query(int p){
        if(p==0)    return 0;
        int res=0;
        while(p){
            res+=bit[p];
            p-=lowbit(p);
        }
        return res;
    }
}lbit,rbit;
struct num{
    int value;
    int pos;
    bool operator<(const num &n)const
    {
        return value<n.value;
    }
}a[maxn];
struct range{
    int l;
    int r;
    bool operator<(const range &rag)const{
        if(r==rag.r)
            return l<rag.l;
        return r<rag.r;
    }
    int p=0;
};
vector<range> vec;
vector<range> q;
void add_pair(int i,int j){vec.push_back({min(i,j),max(i,j),1});}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].value;
        a[i].pos=i;
    }
    sort(a+1,a+1+n);
    add_pair(a[1].pos,a[2].pos);
    add_pair(a[n-1].pos,a[n].pos);
    for(int i=2;i<n;i++)
    {
        int ldif=abs(a[i].value-a[i-1].value);
        int rdif=abs(a[i+1].value-a[i].value);
        if(ldif==rdif){
            add_pair(a[i].pos,a[i-1].pos);
            add_pair(a[i+1].pos,a[i].pos);
        }
        else if(ldif < rdif)
            add_pair(a[i-1].pos,a[i].pos);
        else
            add_pair (a[i+1].pos,a[i].pos);
    }
    sort(vec.begin(),vec.end());
    for(auto a:vec)
    {
        // ;printf("A: %d %d\n",a.l,a.r);
    }
    long long ans=0;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        q.push_back({l,r,i});
    }
    sort(q.begin(),q.end());
    for(int i=0;i<m;i++)
    {
        int l=q[i].l;
        int r=q[i].r;
        long long cur=0;
        while(cnt <vec.size() && vec[cnt].r<=r)
        {
            rbit.add(vec[cnt].r,1);
            lbit.add(vec[cnt].l,1);
            cnt++;
        }
        cur=rbit.query(r)-lbit.query(l-1);
        // printf("CUR: rqr %d lql %d lqr %d\n",rbit.query(r),lbit.query(l-1),rbit.query(l-1));
        cur*=q[i].p;
        ans+=cur;
    }
    cout<<ans<<endl;
    return 0;
}
/*
6 3
1 6 5 3 19 2
2 3
4 6
1 6


1 6
1 6
2 5
2 3
2 3
4 6
4 6
 */
