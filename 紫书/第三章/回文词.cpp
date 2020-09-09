#include <iostream>
#include <string>
int main()
{
    std::string str;
    std::cin>>str;
    bool ok=true;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!=str[str.size()-1-i])
        {
            ok=false;
            break;
        }
    }
    if(ok){
        std::cout<<str<<" is a palindrome"<<std::endl;
    }
    else
    {
        std::cout<<str<<" is not a palindrome"<<std::endl;
    }
    return 0;
}