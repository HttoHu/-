#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 200005;
int arr[maxn];
int main()
{
    priority_queue<int,std::vector<int>, std::greater<int>> min_q;
    priority_queue<int> max_q;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int idx = 1;
    int i = 1;
    for (int k = 1; k <= m; k++)
    {
        int u;
        cin >> u;
        for (; i <= u; i++)
            min_q.push(arr[i]);
        
        max_q.push(min_q.top());
        min_q.pop();
        while (min_q.size() && min_q.top() < max_q.top())
        {
            int tmp = max_q.top();
            max_q.pop();
            int tmp2 = min_q.top();
            min_q.pop();
            max_q.push(tmp2);
            min_q.push(tmp);
        }
        cout<<max_q.top()<<endl;
    }
    return 0;
}