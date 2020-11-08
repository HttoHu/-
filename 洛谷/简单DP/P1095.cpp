#include <iostream>
#include <algorithm>
using namespace std;
int f[300005];
int main(){
    int M,S,T;
    cin>>M>>S>>T;
    for(int i=1;i<=T;i++)
    {
        if(M>=10){
            f[i]=f[i-1]+60;
            M-=10;
        }
        else{
            f[i]=f[i-1];
            M+=4;
        }
    }
    for(int i=1;i<=T;i++)
    {
        f[i]=max(f[i],f[i-1]+17);
        if(f[i]>=S)
        {
            std::cout<<"Yes\n"<<i<<std::endl;
            return 0;
        }
    }  
    std::cout<<"No\n"<<f[T]<<std::endl;
    return 0;
}