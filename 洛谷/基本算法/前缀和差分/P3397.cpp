#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1005;
int arr[maxn][maxn];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int i=a;i<=c;i++)
            for(int j=b;j<=d;j++)
            {
                arr[i][j]++;
            }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<arr[i][j]<<" \n"[j==n];
    return 0;
}