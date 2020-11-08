#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long sum=0;
    long long res=-0x3f3f3f;
    for(int i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        sum+=a;
        res=max(sum,res);
        if(sum<0)
            sum=0;
    }
    cout<<res<<endl;
    return 0;
}