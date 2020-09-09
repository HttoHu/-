#include <iostream>
#include <vector>
#include <string>
using namespace std;
int process(string tmp)
{
    int len=tmp.size();
    int op=0;
    int ret=0;
    for(int i=0;i<len;i++)
    {
        if(tmp[i]=='X')
            op=0;
        else
        {
            op++;
            ret+=op;
        }
    }
    return ret;
}
/*
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX
*/

int main()
{
    std::vector<int> results;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        string tmp;
        std::cin>>tmp;
        results.push_back(process(tmp));
    }
    for(int i=0;i<n;i++)
    {
        std::cout<<results[i]<<std::endl;
    }
    return 0;
}