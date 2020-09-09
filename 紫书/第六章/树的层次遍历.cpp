#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    bool have_value;
    int v;
    Node *left, *right;
    Node() : have_value(false), left(nullptr), right(nullptr) {}
} * root;
bool failed = false;
const int maxn=100;
Node *newnode()
{
    return new Node;
}
void addnode(int v, char *s)
{
    int n = strlen(s);
    Node *u = root;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (u->left == nullptr)
                u->left = newnode();
            u = u->left;
        }
        else if (s[i] == 'R')
        {
            if (u->right == nullptr)
                u->right = newnode();
            u = u->right;
        }
    }
    if (u->have_value)
        failed = true;
    u->v = v;
    u->have_value = true;
}
char s[maxn];
bool read_input()
{
    failed=false;
    root=newnode();
    while(true)
    {
        if(scanf("%s",s)!=1)
            return false;
        if(!strcmp(s,"()"))
            break;
        int v;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;
}
bool bfs(vector<int> &ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node* u=q.front();
        q.pop();
        if(!u->have_value)
            return false;
        ans.push_back(u->v);
        if(u->left!=nullptr)q.push(u->left);
        if(u->right!=nullptr)q.push(u->right);
    }
    return true;
}
int main(){
    read_input();
    vector<int> r;
    bfs(r);
    for(auto a:r)
    {
        std::cout<<a<<" ";
    }
    return 0;
}