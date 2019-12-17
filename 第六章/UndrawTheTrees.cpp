#include <iostream>
#include <string>
/*
2
       A
       |
-----------------
B      C        D
       |        |
    -------     -
    E     F     G
#
e
|
--------
f      g
#
*/
using namespace std;
const int maxn=100+5;
char buf[maxn][maxn];
int n;
void dfs(int r,int c)
{
    cout<<buf[r][c]<<"(";
    if(r+1<n&&buf[r+1][c]=='|')
    {
        int begin_pos=c;
        while(begin_pos>0 && buf[r+2][begin_pos-1]=='-')begin_pos--;
        while(buf[r+2][begin_pos]=='-'&&buf[r+3][begin_pos]!='\0')
        {
            if(!isspace(buf[r+3][begin_pos]))
                dfs(r+3,begin_pos);
            begin_pos++;
        }
    }
    cout<<")";
}
void solve(){
    n=0;
    while(true)
    {
        fgets(buf[n],maxn,stdin);
        if(buf[n][0]=='#')
            break;
        n++;
    }
    cout<<"(";
    if(n){
        for(int i=0;i<strlen(buf[0]);i++){
            if(buf[0][i]!=' ')
            {
                dfs(0,i);
                break;
            }
        }
    }
    cout<<")\n";
}
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--){
        solve();
    }
    return 0;
}