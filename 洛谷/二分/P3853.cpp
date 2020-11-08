#include <iostream>
using namespace std;
int L,N,K;
const int maxn=100005;
int arr[maxn];
void input(){
    cin>>L>>N>>K;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
}

bool check(int x){
    int cnt=0;
    int last=0;
    for(int i=1;i<=N;)
    {
        if(arr[i]-last > x)
        {
            cnt++;
            last+=x;
        }
        else 
        {
            last=arr[i];
            i++;
        }
        if(cnt>K)
            return false;
    }
    return cnt<=K;
}
int main(){
    input();
    int L=arr[1], R=arr[N]+1;
    while(L<R){
        int m=(L+R)/2;
        if(check(m))
            R=m;
        else 
            L=m+1;
    }
    std::cout<<R;
    return 0;
}