#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
const int maxn=2000005;
int a[maxn];
struct Pair
{
    int num;
    int pos;
    bool operator<(const Pair&p)const
    {
        return num<p.num;
    }
};
using namespace std;
int main(){
    set<int,std::greater<int>> s;
    priority_queue<Pair> q;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=k;i++)
    {
        q.push({a[i],i});
    }
    cout<<q.top().num<<endl;
    for(int i=k+1;i<=n;i++)
    {
        q.push({a[i],i});
        while(q.top().pos < i-k)
            q.pop();
        cout<<q.top().num<<endl;
    }
    return 0;
}   