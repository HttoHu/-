#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
    int x;
    int idx;
    bool operator<(const Node & n)const {return x<n.x;}
    bool operator> (const Node &n)const{return x>n.x;}
};
const int maxn=100005;
Node a[maxn];
Node b[maxn];
int f[maxn];
int tmp[maxn];
int n;
void input(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
        a[i].idx=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].x;
        b[i].idx=i;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
        f[b[i].idx]=a[i].idx;
}
long long res=0;
const long long mod=1e8-3;
void merge_sort(int left,int right)
{
    if(left==right)
        return;
    int mid=(left+right)/2;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    int k=left;
    int i=left,j=mid+1;
    while(i<=mid && j<=right)
    {
        if(f[i]<f[j]) tmp[k++]=f[i++];
        else{
            res+=mid-i+1;
            res%=mod;
            tmp[k++]=f[j++];
        }
    }
    while(i<=mid) tmp[k++]=f[i++];
    while(j<=right) tmp[k++]=f[j++];
    for(int i=left;i<=right;i++)
        f[i]=tmp[i];
}
int main(){
    input();
    merge_sort(1,n);
    cout<<res;
    return 0;
}