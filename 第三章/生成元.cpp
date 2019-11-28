#include <iostream>
int get_v(int v)
{
    int ret=v;
    while (v!=0)
    {
        ret+=v%10;
        v/=10;
    }
    return ret;
}
int main()
{
    int n;
    std::cin>>n;
    for(int i=0;i<100000;i++)
    {
        if(get_v(i)==n)
        {
            std::cout<<i;
            break;
        }
    }
    return 0;
}