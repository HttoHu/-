#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;
int n;
struct Ship
{
    int t;
    int n;
    std::vector<int> people;
};
deque<Ship> deq;
int table[100005];
int change(Ship& s,int x)
{
    int res=0;
    for(auto it: s.people)
    {
        if(table[it]==-x)
            res--;
        else if(table[it]==0 && x>0)
            res++;
        table[it]+=x;
    }
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        Ship cur_ship;
        int t,k;
        scanf("%d%d",&t,&k);
        cur_ship.n=k,cur_ship.t=t;
        for(int j=0;j<k;j++)
        {
            int a;
            scanf("%d",&a);
            cur_ship.people.push_back(a);
        }
        deq.push_back(cur_ship);
        res+=change(cur_ship,1);
        while(deq.size() && cur_ship.t-deq.front().t>= 86400)
        {
            res+=change(deq.front(),-1);
            deq.pop_front();
        }
        printf("%d\n",res);
    }
}
int main(){
    solve();
    return 0;
}
