#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Rect
{
    long long x1, y1, x2, y2;
    long long area()
    {
        return (long long)(y1 - y2) * (x2 - x1);
    }
    void print()
    {
        // printf("(%d,%d,%d,%d)\n", x1, y1, x2, y2);
    }
};
const int maxn = 10005;
vector<Rect> rects;
void add(int x1, int y1, int x2, int y2)
{
    rects.push_back({x1, y1, x2, y2});
}

void cut(Rect r1, Rect r2, int l_mod)
{
    // 先切掉x轴
    if (l_mod)
    {
        long long k1 = max(r1.x1, r2.x1);
        long long k2 = min(r1.x2, r2.x2);
        if (r1.x1 < k1)
            add(r1.x1, r1.y1, k1, r1.y2);
        if (r1.x2 > k2)
            add(k2, r1.y1, r1.x2, r1.y2);
        cut(r1, Rect{k1, r2.y1, k2, r2.y2}, 0);
    }
    // 切切y轴
    else
    {
        long long k1 = min(r1.y1, r2.y1);
        long long k2 = max(r1.y2, r2.y2);
        if (r1.y1 > k1)
            add(r2.x1, r1.y1, r2.x2, k1);
        if (r1.y2 < k2)
            add(r2.x1, k2, r2.x2, r1.y2);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Rect r = {a, b, c, d};
        if (rects.empty())
            add(a, b, c, d);
        else
        {
            for (int i = 0; i < rects.size(); i++)
            {
                auto &r2 = rects[i];
                if (r.x2 <= r2.x1 || r.y2 >= r2.y1 || r2.x2 <= r.x1 || r2.y2 >= r.y1)
                    continue;
                cut(r2, r, 1);
                if (rects.size() != 1)
                {
                    rects[i] = rects.back();
                    rects.pop_back();
                    i--;
                }
            }
            add(a, b, c, d);
        }
    }
    long long res = 0;
    for (auto a : rects)
    {
        res += a.area();
    }
    cout << res;
    return 0;
}