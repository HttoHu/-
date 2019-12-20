#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
DBACEGF ABCDEFG 
*/
char tree[1024];
string pre_str;
string in_order_str;
void build_tree(int cur_node, int p1, int p2, int i1, int i2)
{
    if(p1>p2||i1>i2){return;}
    char ch = pre_str[p1];

    int right_center = -1;
    for (int i = i1; i <= i2; i++)
    {
        if (in_order_str[i] == ch)
        {
            right_center = i;
            break;
        }
    }
    if(right_center==-1)
        return;
    int mov=right_center-i1;

    build_tree(cur_node * 2, p1 + 1, p1+1+mov, i1, right_center-1);
    build_tree(cur_node * 2 + 1, p1+1+mov, p2, right_center + 1, i2);
    tree[cur_node] = ch;
    cout<<ch;
}
void post_dfs(int cur_node=1){
    if(tree[cur_node]==0){
        return;
    }
    post_dfs(cur_node*2);
    post_dfs(cur_node*2+1);
    cout<<tree[cur_node];
}
int main()
{
    memset(tree,0,sizeof(tree));
    cin>>pre_str;
    cin>>in_order_str;
    build_tree(1,0,pre_str.size()-1,0,in_order_str.size()-1);
    //post_dfs();
    return 0;
}