#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1005;
int a[maxn][maxn];
long long s[maxn][maxn];
int n,m,c;
int main(){
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    long long res=-0x3f3f3f3f3f3f;
    int rx,ry;
    for(int x=c;x<=n;x++)
        for(int y=c;y<=m;y++)
        {
            if(res < s[x][y]-s[x-c][y]-s[x][y-c]+s[x-c][y-c])
            {
                res = s[x][y]-s[x-c][y]-s[x][y-c]+s[x-c][y-c];
                rx=x-c+1;
                ry=y-c+1;
            }
        }
    cout<<rx<<" "<<ry;
    return 0;
}
