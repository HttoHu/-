#include <math.h>
#include <iostream>
bool is_square(int x){
    for(int i=0;i*i<=x;i++)
    {
        if(i*i==x)
            return true;
    }
    return false;
}
int main()
{
    for(int a=1;a<=9;a++)
    {
        for(int b=0;b<=9;b++)
        {
            int n=a*1000+a*100+b*10+b;
            if(is_square(n))
                std::cout<<n<<std::endl;
        }
    }
    return 0;
}