#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=500005;
int rain_tree[maxn];
int year[maxn];
int rain[maxn];
int n,m;
/*
6
1 1
2 2
3 3 
5 5
7 7
8 8
5
1 1
3 5
4 7
6 8
8 10

*/
int ls(int k){return 2*k;}
int rs(int k){return 2*k+1;}
void push_up(int k){
    rain_tree[k]=max(rain_tree[ls(k)],rain_tree[rs(k)]);
}
void init(int k,int L,int R)
{
    if(L==R)
        rain_tree[k]=rain[L];
    else{
        int mid=(L+R)/2;
        init(ls(k),L,mid);
        init(rs(k),mid+1,R);
        push_up(k);
    }
}
int query(int k,int l,int r,int L,int R)
{
    if(l>R || L>r) return 0;
    if(l<=L && r>=R )return rain_tree[k];
    int res=0;
    int mid=(L+R)/2;
    if(l<=mid) res=max(res,query(ls(k),l,r,L,mid));
    if(r>mid) res=max(res, query(rs(k),l,r,mid+1,R));
    return res;
}
string solve(int from,int to)
{
    int l=upper_bound(year+1,year+n+1,from)-year;
    int r=lower_bound(year+1,year+1+n,to)-year;
    r--;
    int ans=query(1,l,r,1,n);
    //printf("(%d,%d,%d)\n",l,r,ans);
    if(year[l-1]==from && ans >= rain[l-1])
        return "false\n";
    else if(year[r+1]==to && ans >= rain[r+1])
        return "false\n";
    else if(year[r+1]== to && year[l-1]==from && rain[r+1]>=rain[l-1])
        return "false\n";
    else if(year[l-1]!=from || year[r+1]!=to)
        return "maybe\n";
    else if(r-l+2!=to-from)
        return "maybe\n";
    return "true\n";
}
// 
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>year[i];
        cin>>rain[i];
    }
    init(1,1,n);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y);
    }
    return 0;
}