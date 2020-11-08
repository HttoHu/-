#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream ifs("input.txt");
ofstream ofs("output.txt");
int n;
long long cur_ans = -1;
long long cur_k=1;
vector<int> ans;
const int maxn = 100005;
int a[maxn];
long long s[maxn];
struct Num
{
    int num;
    int idx;
};

void solve()
{
    deque<Num> min_q;
    deque<Num> max_q;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
        while (!min_q.empty() && min_q.back().num >= a[i])
            min_q.pop_back();
        min_q.push_back({a[i], i});
    }
    for (int k = 1; k <= n-2; k++)
    {
        long long sum = s[n] - s[k];
        while (!min_q.empty() && min_q.front().idx <= k)
            min_q.pop_front();
        sum -= min_q.front().num;
        if (sum * cur_k  > cur_ans * (n-k-1))
        {
            ans.clear();
            cur_ans = sum;
            cur_k=n-k-1;
        }
        if(sum * cur_k  == cur_ans * (n-k-1))
            ans.push_back(k);
    }
}
int main()
{
    memset(s, 0, sizeof(s));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
    for (auto it : ans)
        cout << it <<endl;
    return 0;
}