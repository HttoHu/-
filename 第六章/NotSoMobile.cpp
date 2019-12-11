/*
1
0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2
*/
#include <iostream>
#include <string>
struct Tree
{
    int l_w=0;
    int r_w=0;
    Tree *left = nullptr;
    int l_length;
    Tree *right = nullptr;
    
    int r_length;
    bool test_balance()
    {
        if(l_w)
        {
            if(!left->test_balance())
                return false;
        }
        if(r_w)
        {
            if(!right->test_balance())
                return false;
        }
        return l_length*left_v() == r_length*right_v();
    }
    int left_v()
    {
        if (left ==nullptr)
        {
            return l_w;
        }
        return left->left_v() +left->right_v();
    }
    int right_v()
    {
        if(right==nullptr)
            return r_w;
        return right->right_v()+right->left_v();
    }
};
Tree *root;
int cur_index = 0;
int n = 0;
Tree *build_tree()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    Tree *ret = new Tree;
    ret->l_length = b;
    ret->r_length = d;
    ret->l_w=a;
    ret->r_w=c;
    if (a == 0)
    {
        Tree *left_node = build_tree();
        ret->left = left_node;
    }
    if (c == 0)
    {
        Tree *right_node = build_tree();
        ret->right = right_node;
    }
    return ret;
}
int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        root = build_tree();
        if (root->test_balance())
        {
            std::cout << "YES";
        }
        else
        {
            std::cout << "NO";
        }
        return 0;
    }
}