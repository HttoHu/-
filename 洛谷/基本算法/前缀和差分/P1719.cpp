#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 125;
int a[maxn][maxn];
int tmp[maxn];
int n;
int get_max()
{
    int res = -0x3f3f3f3f;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += tmp[i];
        res = max(sum, res);
        if (sum < 0)
            sum = 0;
    }
    return res;
}
int main()
{
    cin >> n;
    int res = -0x3f3f3f;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int s = 1; s <= n; s++)
    {
        memset(tmp, 0, sizeof(tmp));
        for (int e = s; e <= n; e++)
        {
            for (int i = 1; i <= n; i++)
                tmp[i] += a[e][i];
            res = max(res, get_max());
        }
    }
    cout << res << endl;
    return 0;
}