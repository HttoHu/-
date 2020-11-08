#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
bool solve()
{
    int n;
    cin>>n;
    vector<int> vec;
    vector<int> vec2;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vec2.push_back(x);
    }
    vector<int> vec3;
    int cnt=0;
    for(int i=0;i<n;)
    {
        while (vec3.empty() || vec3.back()!=vec2[i])
        {
            
            if(cnt>=n)
                return false;
            vec3.push_back(vec[cnt++]);
        }
        while(vec3.size()&&vec3.back()==vec2[i])
        {
            vec3.pop_back();
            i++;
        }
    }
    return true;
}
int main(){
    int kase=0;
    cin>>kase;
    while(kase--)
    {
        if(solve())
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}