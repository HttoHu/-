#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
struct Grass
{
    long long p;
    long long w;
    bool operator<(const Grass &g) const
    {
        return p < g.p;
    }
};
const int maxn = 100005;
long long N, B;
Grass gra[maxn];
ifstream ifs("input.txt");
void input()
{
    cin >> N >> B;
    for (int i = 1; i <= N; i++)
        cin >> gra[i].w >> gra[i].p;
    sort(gra + 1, gra + N + 1);
}
int main()
{
    input();
    int st=lower_bound(gra+1,gra+1+N,Grass{B,0})-gra;
    st-=1;
    int l=st;
    int r=st+1;
    long long ans=0x3f3f3f3f3f3f3f3f;
    while(l>=1)
    {
        while(r<=N && (gra[r].p-gra[l].p)>gra[r].w)
            r++;
        if(r>N)
            break;
        ans=min(ans,gra[r].p-gra[l].p-gra[l].w);
        l--;
    }
    l=st;
    r=st+1;
    while(r<=N)
    {
        while(l>=1 && (gra[r].p-gra[l].p) > gra[l].w)
            l--;
        if(l<1)
            break;
        ans=min(ans,gra[r].p-gra[l].p-gra[r].w);
        r++;
    }
    if(ans==0x3f3f3f3f3f3f3f3f)
        cout<<-1;
    else if(ans<=0)
        cout<<0;
    else 
        cout<<ans;
    return 0;
}