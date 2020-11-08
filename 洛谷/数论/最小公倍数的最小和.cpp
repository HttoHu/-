#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream ifs("input.txt");
ofstream ofs("output.txt");
const int maxn=600005;
long long pt[maxn],cnt=0;
int e[maxn];
void build_pt(){
    for(int i=2;i<=maxn-5;i++)
    {
        bool prime=true;
        for(int j=i;j*j<=i;j++)
        {
            if(i%j==0)
            {
                prime=false;
                break;
            }
        }
        if(prime)
            pt[cnt++]=i;
    }
}
long long solve(long long n)
{
    if(n==1)
        return 2;
    int f_cnt=0;
    long long sum=0;
    for(int i=0;i<cnt;i++)
    {
        int cur_res=1;
        int j=0;
        while(n%pt[i]==0)
        {
            j++;
            n/=pt[i];
        }
        if(j){
            f_cnt++;
            //printf("%lld %d \n",pt[i],j);
            sum+=pow(pt[i],j);
        }
    }
    if(n!=1)
        sum+=n;
    if(f_cnt==0)
        return sum+1;
    if(f_cnt==1 && n!=1)
        return sum;
    else if(f_cnt==1)
        return sum+1;
    return sum;
}
int main(){
    long long kase=1,n;
    build_pt();
    while(scanf("%lld",&n)&&n)
        cout<<"Case "<<kase++<<": "<<solve(n)<<endl;
    return 0;
}