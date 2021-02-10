#include <iostream>
#include <vector>
using namespace std;
const int maxn=10005;
int phi[maxn];
void init(int n){
    for(int i=1;i<=n;i++)
        phi[i]=i;
    for(int i=2;i*i<=n;i++)
        if(phi[i]==i)
            for(int j=i;j<=n;j+=i)
                phi[j]=phi[i]/i *(i+1);
        
}
int isnp[maxn];
void init2(int n){
    vector<int> primes;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!isnp[i])
            primes.push_back(i);
        for(auto p:primes)
        {
            if(i*p>n) break;
            isnp[i*p]=1;
            if(p%i==0){
                phi[p*i]=phi[i]*p;
                break;
            }
            else
                phi[p*i]=phi[p]*phi[i];
            
        }
    }
}

int main(){
    
}