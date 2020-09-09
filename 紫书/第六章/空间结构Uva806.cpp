#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <string.h>
using namespace std;
void trans_number_set(const deque<int> &deq);
deque<int> trans_number(int n);
const int maxn = 100 + 5;
int tree[4 * 4 * 4 * 4 * 4 * 4];
int buf[maxn][maxn];
int image_count = 1;
string output;
void trans_pic(int cur_node, int r, int c, int w)
{
    if (w == 1)
    {
        tree[cur_node] = buf[r][c];
        return;
    }
    bool all_dark = true;
    bool have_dark = false;
    for (int i = r - w + 1; i <= r; i++)
    {

        for (int j = c - w + 1; j <= c; j++)
        {
            if (buf[i][j] != 1)
                all_dark = false;
            else
                have_dark = true;
        }
    }
    if (all_dark)
    {
        tree[cur_node] = 1;
        return;
    }
    else if (have_dark)
        tree[cur_node] = 2;
    else
        return;
    trans_pic(cur_node * 4 - 2, r - w / 2, c, w / 2);
    trans_pic(cur_node * 4 - 1, r, c, w / 2);
    trans_pic(cur_node * 4, r - w / 2, c - w / 2, w / 2);
    trans_pic(cur_node * 4 + 1, r, c - w / 2, w / 2);
}
deque<int> numbers;
void tree_trans_to_numbers(int cur_node, int product)
{
    if (tree[cur_node] == 1)
    {
        auto rev = trans_number(product);
        int tmp = 0;
        for (int i = 0; i < rev.size(); i++)
        {
            tmp = tmp * 5 + rev[i];
        }
        numbers.push_back(tmp);
        return;
    }
    if (!tree[cur_node])
        return;
    tree_trans_to_numbers(cur_node * 4 - 2, product * 5 + 1);
    tree_trans_to_numbers(cur_node * 4 - 1, product * 5 + 2);
    tree_trans_to_numbers(cur_node * 4, product * 5 + 3);
    tree_trans_to_numbers(cur_node * 4 + 1, product * 5 + 4);
}
deque<int> trans_number(int n)
{
    deque<int> ret;
    while (n != 0)
    {
        ret.push_back(n % 5);
        n /= 5;
    }
    return ret;
}
void draw_buf(int cur_node, int r, int c, int w)
{
    if (tree[cur_node] == 2)
    {
        draw_buf(cur_node * 4 - 2, r - w / 2, c, w / 2);
        draw_buf(cur_node * 4 - 1, r, c, w / 2);
        draw_buf(cur_node * 4, r - w / 2, c - w / 2, w / 2);
        draw_buf(cur_node * 4 + 1, r, c - w / 2, w / 2);
        return;
    }
    int color = tree[cur_node];
    if (w == 1)
    {
        buf[r][c] = color;
        return;
    }
    for (int i = r - w + 1; i <= r; i++)
    {
        for (int j = c - w + 1; j <= c; j++)
        {
            buf[i][j] = color;
        }
    }
}
void trans_number_set(const deque<int> &deq)
{
    for (auto a : deq)
    {
        auto pos = trans_number(a);
        int node_pos = 1;
        for (auto b : pos)
        {
            int rp = b - 3;
            tree[node_pos] = 2;
            node_pos = node_pos * 4 + rp;
        }
        tree[node_pos] = 1;
    }
}
void draw_driver(int n)
{
    deque<int> deq;
    int tmp;
    while (true)
    {
        cin>>tmp;
        if (tmp == 0)
        {
            cin>> tmp;
            output+= "Image " +to_string(image_count++)+"\n";
            for (int i = 0; i < -n; i++)
            {
                for(int j=0;j<-n;j++){
                    output+="*";
                }
                output+='\n';
            }
            output+='\n';
            return;
        }
        if (tmp == -1)
            break;
        deq.push_back(tmp);
    }
    for (auto a : deq)
    {
        auto nums = trans_number(a);
        int cur_node = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            tree[cur_node] = 2;
            cur_node = cur_node * 4 + (nums[i] - 3);
            if (i == nums.size() - 1)
            {
                tree[cur_node] = 1;
                break;
            }
        }
    }
    draw_buf(1, -n - 1, -n - 1, -n);
    n = -n;
    output+= "Image " +to_string(image_count++)+"\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output+= ".*"[buf[j][n - 1 - i]];
        }
        output+="\n";
    }
    output+='\n';
}
int main()
{
    while (true)
    {
        numbers.clear();
        memset(buf, 0, sizeof(buf));
        memset(tree, 0, sizeof(tree));
        int n;
        cin >> n;
        if (n == 0)
            break;
        if (n < 0)
        {
            draw_driver(n);
            continue;
        }
        getchar();
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                buf[j][i] = getchar() - 48;
            }
            getchar();
        }
        trans_pic(1, n - 1, n - 1, n);
        tree_trans_to_numbers(1, 0);
        sort(numbers.begin(), numbers.end());
        output+= "Image " +to_string(image_count++)+"\n";
        for (int i = 0; i < numbers.size(); i++)
        {
            output+=to_string(numbers[i])+' ';
            if((i+1)%12==0){
                output+='\n';
            }
        }
        output+= "Total number of black nodes = " +to_string(numbers.size())+"\n\n";
    }
    cout<<output;
    return 0;
}
