#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
const int maxn = 20100000;
int a[maxn];
int n, m;
using namespace std;
deque<int> q;
int main()
{
    memset(a,0,sizeof(a));
    q.clear();
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d",a+i);
    printf("0\n");
    for (int i = 1; i <n; i++)
    {
        while (!q.empty() && a[q.back()] >= a[i])
            q.pop_back();
        q.push_back(i);
        while (!q.empty() && q.front() + m <= i)
            q.pop_front();
        if(q.empty())
        {
            cout<<"11DAMN IT";
            return 0;
        }
        printf("%d\n",a[q.front()]);
    }
    return 0;
}