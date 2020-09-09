#include <iostream>
#include <algorithm>
// ???????
using namespace std;
const int INF = 100000;
const int maxn = 1000 + 5;
int map[maxn][maxn], d[maxn][maxn], next_row[maxn][maxn];
int main()
{
    int r, c;
    while (cin >> r >> c && r && c)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> map[i][j];
        int ans = INF, first = 0;
        for (int j = c - 1; j >= 0; j--)
            for (int i = 0; i < r; i++)
            {
                if (j == c - 1)
                    d[i][j] = map[i][j];
                else
                {

                    int rows[3] = {i, i + 1, i - 1};
                    if (i == r - 1)
                        rows[1] = 0;
                    else if (i == 0)
                        rows[2] = r - 1;
                    sort(rows, rows + 3);
                    d[i][j] = INF;
                    for (int k = 0; k < 3; k++)
                    {
                        int v = d[rows[k]][j + 1] + map[i][j];
                        if (v < d[i][j])
                        {
                            d[i][j] = v;
                            next_row[i][j] = rows[k];
                        }
                    }
                }
                if(j==0&&ans>d[i][j]){ans=d[i][j];first=i;}
            }
        std::cout<<first+1<<" ";
        for(int i=next_row[first][0],j=1;j<c;i=next_row[i][j],j++) std::cout<<i+1<<" ";
        std::cout<<"\n"<<ans<<"\n";
    }
    return 0;
}