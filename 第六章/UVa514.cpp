#include <iostream>
#include <vector>
using namespace std;
std::vector<int> carrage_set;
std::vector<int> test;
bool match(int j,int k)
{
    for(int i=j;i<=k;i++)
    {
        if(carrage_set[i]!=test[k-(i-j)])
        {
            return false;
        }
    }
    return true;
}
bool test_n(int n)
{
    for(int i=0;i<n;i++)
    {
        int index=i;
        if(carrage_set[i]!=test[i])
        {
            while (index<n && carrage_set[i]!=test[i])
            {
                index++;
                continue;
            }
            return match(i,index-1);
        }
    }
    return true;
}
int main()
{
    int n;
    std::cin>>n;
    for (int i=0;i<n;i++)
    {
        carrage_set.push_back(i+1);
    }
    for (int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        test.push_back(tmp);
    }
    std::cout<<test_n(n);
    while(1)
        std::cin.get();
    return 0;
}