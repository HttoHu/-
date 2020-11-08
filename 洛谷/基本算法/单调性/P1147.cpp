#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long get_sum(long long l,long long r)
{
    return (r+1)*r/2-((l)*(l-1)/2);
}
int main(){
    int l=1,r=1;
    int m;
    cin>>m;
    while(l<(m/2)+1)
    {
        while(get_sum(l,r)<m)
            r++;
        if(get_sum(l,r)==m)
            printf("%d %d\n",l,r);
        else 
            r--;
        l++;
    }
    return 0;
}