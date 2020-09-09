#include <iostream>
#include <vector>
#include <map>
#include <stack>
struct Set;
/*
2
9
PUSH
DUP
ADD
PUSH
ADD
DUP
ADD
DUP
UNION
5
PUSH
PUSH
ADD
PUSH
INTERSECT
*/
struct Set
{
    std::vector<Set> childs;
    bool equate(const Set& s)
    {
        if(empty()&&s.empty())
        {
            return true;
        }
        if(s.childs.size()!=childs.size())
            return false;
        for(auto &a:childs)
        {
            bool ok=false;
            for(auto &b:s.childs)
            {
                if(a.equate(b))
                    ok=true;
            }
            if(ok==false)
                return false;
        }
        return true;
    }
    bool empty()const{
        return childs.size()==0;
    }
    Set add(Set s){
        Set ret=*this;
        ret.childs.push_back(s);
        return ret;
    }
    Set set_union(Set s)
    {
        for(auto &a:s.childs)
        {
            for(auto &b:childs)
            {
                bool ok=false;
                for(auto &b:s.childs)
                {
                    if(a.equate(b))
                    ok=true;
                }
                if(ok==false)
                {
                    s.childs.push_back(b);
                }
            }
        }
        return s;
    }
    Set intersect(Set s)
    {
        Set ret;
        for(auto &a:s.childs)
        {
            for(auto &b:childs)
            {
                bool ok=false;
                for(auto &b:s.childs)
                {
                    if(a.equate(b))
                    ok=true;
                }
                if(ok==true)
                {
                    ret.childs.push_back(a);
                }
            }
        }
        return ret;
    }
};
std::vector<std::string> ins;
std::vector<int> results;
std::vector<Set> my_stack;
void input(int count)
{
    for(int i=0;i<count;i++)
    {
        std::string str;
        std::cin>>str;
        ins.push_back(str);
    }
}
void execute()
{
    for(auto a:ins)
    {
        if(a=="PUSH")
            my_stack.push_back(Set());
        else if(a=="DUP")
        {
            my_stack.push_back(my_stack.back());
        }
        else if(a=="UNION")
        {
            auto tmp=my_stack.back();
            my_stack.pop_back();
            auto tmp2=my_stack.back();my_stack.pop_back();
            my_stack.push_back(tmp2.set_union(tmp));
        }
        else if(a=="ADD")
        {
            auto tmp=my_stack.back();
            my_stack.pop_back();
            auto tmp2=my_stack.back();my_stack.pop_back();
            my_stack.push_back(tmp.add(tmp2));
        }
        else if(a=="INTERSECT")
        {
            auto tmp=my_stack.back();
            my_stack.pop_back();
            auto tmp2=my_stack.back();my_stack.pop_back();
            my_stack.push_back(tmp.intersect(tmp2));
        }
        results.push_back(my_stack.back().childs.size());
    }
}
void show_results()
{
    for(auto a:results)
        std::cout<<a<<std::endl;
    std::cout<<"***\n";
}
int main()
{
    int p_count;
    std::cin>>p_count;
    for(int i=0;i<p_count;i++)
    {
        int n=0;
        std::cin>>n;
        input(n);
        execute();
        show_results();
        ins.clear();
    
        results.clear();
    }
}