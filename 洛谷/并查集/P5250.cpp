#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<int> table;
int erase(int x)
{
    table.insert(x);
    auto it = table.find(x);
    if (it == table.begin())
    {
        return *(++it);
    }
    int a=*(++it);
    if(it==table.end())
    {
        return *(--(--it));
    }
    it--;it--;
    int b=*it;
    //printf("%d,%d\n",a,b);
    int fir=abs(a-x);
    int sec=abs(b-x);
    if(fir<sec) return a;
    else if(sec<fir) return b;
    else return min(a,b);
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            if (table.count(b))
                std::cout << "Already Exist\n";
            else
                table.insert(b);
        }
        else
        {

            if (table.empty())
                std::cout << "Empty\n";
            else if(table.count(b))
            {
                table.erase(b);
                std::cout<<b<<std::endl;
            }
            else if(table.size()==1)
            {
                std::cout<<*table.begin()<<std::endl;
                table.erase(table.begin());
            }
            else
            {
                int res = erase(b);
                std::cout << res << endl;
                table.erase(res);
                table.erase(b);
            }
        }
    }
    return 0;
}