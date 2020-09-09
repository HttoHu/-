/*
    平衡的括号Uva673.cpp
    嘎嘎嘎，终于有一个签到题
*/
#include <iostream>
#include <vector>
#include <string>
bool is_parentheses(char ch){
    return ch=='['||ch==']'||ch=='('||ch==')';
}
bool match(char a,char b){
    return (a=='['&&b==']')||(a=='('&&b==')');
}
int main()
{
    using namespace std;
    vector<char> parent_stack;
    string tmp;
    cin>>tmp;
    bool ok=true;
    for(auto a:tmp){
        if(!is_parentheses(a))
        {
            ok=false;
            break;
        }
        parent_stack.push_back(a);
        if(parent_stack.size()>=2){
            char a=parent_stack.back();
            parent_stack.pop_back();
            char b=parent_stack.back();
            parent_stack.pop_back();
            if(match(a,b)){ok=false;break;}
        }
    }
    if(ok&&parent_stack.empty()){
        std::cout<<"OJBK";
    }
    else
    {
        cout<<"DAMN IT";
    }
    return 0;
    
}