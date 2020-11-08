#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 25;
int vis[maxn];
string arr[maxn];
int N;
void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
}
int check(string s1,string s2)
{
    int sz=min(s1.size(),s2.size());
    for(int i=0;i<sz;i++)
    {
        bool ok=true;
        for(int j=0;j<=i;j++)
        {
            if(s1[s1.size()-i-1+j]!=s2[j])
            {
                ok=false;
                break;
            }
        }
        if(ok)
            return i+1;
    }
    return -1;
}
int cur_ans = 0;
int dfs(int ans, int last)
{
    int res=ans;
    for (int i = 1; i <= N; i++)
    {
        if (vis[i]==2)
            continue;
        int c=check(arr[last],arr[i]);
        if(c==-1)
            continue;
        // cout<<arr[last]<<" with "<<arr[i]<<" : ";
        // printf("%d cur_ans: %d\n",c,ans+(int)arr[i].size()-c);
        vis[i]++;
        res=max(res,
            dfs(ans + arr[i].size()-c, i));
        vis[i]--;
    }
    return res;
}
int main()
{
    input();
    char ch;
    cin >> ch;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i][0] == ch)
        {
            vis[i] = 1;
            cur_ans=max(cur_ans,dfs(arr[i].size(), i));
            vis[i] = 0;
        }
    }
    std::cout << cur_ans << endl;
    return 0;
}