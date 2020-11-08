#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str1;
string str2;
const int maxn=1005;
int f[maxn][maxn];
int main(){
    cin>>str1;
    int N=str1.size();
    str2.resize(N);
    for(int j=str1.size()-1;j>=0;j--)
        str2[str1.size()-j-1]=str1[j];

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(str1[i-1]==str2[j-1])
                f[i][j]=f[i-1][j-1]+1;
            else 
                f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    std::cout<<N-f[N][N]<<std::endl;
}