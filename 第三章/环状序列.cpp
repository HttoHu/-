#include<iostream>
#include<string>
using namespace std;
string cur_min="";
bool mless(string a)
{
    int length=a.size();
    for(int i=0;i<length;i++)
    {
        if(a[i]<cur_min[i])
        {
            return true;
        }
        if(a[i]==cur_min[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return false;
}
int main()
{
    string input;
    std::cin>>input;
    cur_min=input;
    int length=input.size();
    for(int i=0;i<length;i++)
    {
        if(mless(input))
        {
            cur_min=input;
        }
        char e=input[length-1];
        for(int i=length-1;i>0;i--)
        {
            input[i]=input[i-1];
        }
        input[0]=e;
    }
    std::cout<<cur_min;
    return 0;
}