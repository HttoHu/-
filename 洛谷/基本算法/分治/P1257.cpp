#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <fstream>
using namespace std;
ifstream ifs("input");
long double square(long double x)
{
    return x * x;
}
using ll = long long;
const int maxn = 2000005;
struct Pos
{
    long double x;
    long double y;
    long double get_dis(Pos &p)
    {
        return sqrt(square(x - p.x) + square(y - p.y));
    }
    bool operator<(const Pos &p) const
    {
        if (x == p.x)
            return y < p.y;
        return x < p.x;
    }
} arr[maxn];
int tmp[maxn];
bool cmpy(int x, int y)
{
    return arr[x].y<arr[y].y;
}

long double solve(int left, int right)
{
    long double res = 1e11;
    if (left == right)
        return 1e11;
    if (right - left == 1)
        return arr[right].get_dis(arr[left]);
    int mid = (right + left) / 2;
    res = min(solve(left, mid), solve(mid + 1, right));
    int k=0;
    for(int i=left;i<=right;i++)
        if(fabs(arr[i].x-arr[mid].x) <=res)
            tmp[k++]=i;
    sort(tmp,tmp+k,cmpy);
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k && arr[tmp[j]].y - arr[tmp[i]].y<=res;j++)
            res=min(res,arr[tmp[j]].get_dis(arr[tmp[i]]));
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + n);
    printf("%.4Lf",solve(0, n - 1));
    return ~~(0-0);
}