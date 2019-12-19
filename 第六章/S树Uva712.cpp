#include <iostream>
#include <vector>
#include <stack>
// 我没有调额，居然可行。。。。。我刷着知乎写着代码，一次成功，我自己都不敢相信了。
/*

3
x1 x2 x3
00000111
4
000
010
111
110
3
x3 x1 x2
00010011
4
000
010
111
110
0
*/
using namespace std;
int tree[1024];
int depth;
void fill_tree(int cur_depth, int cur_node, string str, int &n)
{
    if (n >= str.size())
        return;
    if (cur_depth == depth)
    {
        tree[cur_node] = str[n++] - 48;
        return;
    }
    fill_tree(cur_depth + 1, cur_node * 2, str, n);
    fill_tree(cur_depth + 1, cur_node * 2 + 1, str, n);
}
string search(const vector<string> &vec, const vector<int> &order)
{
    string ret;
    for (auto b : vec)
    {
        int seeker=1;
        int val=0;
        for (auto a : order)
        {
            val = b[a] - 48;
            if(val){seeker=seeker*2+1;}
            else{seeker*=2;}
        }
        val=tree[seeker];
        ret+=(char)(val+48);
    }
    return ret;
}
int main()
{
    int program_count = 1;
    while (true)
    {
        memset(tree, -1, sizeof(tree));
        vector<int> order;
        vector<string> input_vec;
        int n;
        cin >> n;
        if (n == 0)
            break;
        depth = n + 1;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            order.push_back(tmp[1] - 48 - 1);
        }
        string leaves;
        cin >> leaves;
        int index = 0;
        fill_tree(1, 1, leaves, index);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            input_vec.push_back(tmp);
        }
        cout << "S-Tree #" << program_count++ << ":" << endl;
        cout << search(input_vec, order)<<endl;
    }
    return 0;
}