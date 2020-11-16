#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
int a[10005];
long long solve(int left,int right)
{
    if(left==right)
        return a[left];
    int mid=(left+right)/2;
    return solve(left,mid)+solve(mid+1,right);
}
int main(){
    string str;
    getline(std::cin,str);
    stringstream ss(str);
    int n=0;
    long long t;
    long long s=0;
    while(ss>>t)
    {    
        s+=t;
        n++;
    }
    cout<<s*(long long)pow<long long>(2,n-1);
}