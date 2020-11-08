#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
char str[500];
int matched[500];
int nxt[500];
int prv[500];
int cnt = 0;
void insert_after(char ch, int pos)
{
    str[++cnt] = ch;
    if (nxt[pos] != -1)
    {
        int old_next = nxt[pos];
        prv[old_next] = cnt;
        nxt[cnt] = old_next;
    }
    else
        nxt[cnt] = -1;
    prv[cnt] = pos;
    nxt[pos] = cnt;
}
void insert_before(char ch, int pos)
{
    str[++cnt] = ch;
    if (prv[pos] != -1)
    {
        int old_prv = prv[pos];
        nxt[old_prv] = cnt;
        prv[cnt] = old_prv;
    }
    else
        prv[cnt] = -1;
    prv[pos] = cnt;
    nxt[cnt] = pos;
}
void fix(int from, int to)
{
    vector<int> last_p;
    vector<int> last_s;
    int next = from;
    while (next != to)
    {
        if (matched[next])
        {
            next = nxt[next];
            continue;
        }
        if (str[next] == '(')
            last_p.push_back(next);
        else if (str[next] == '[')
            last_s.push_back(next);
        else if (str[next] == ')')
        {
            int cur_prv=prv[next];
            while(cur_prv!=-1 && matched[cur_prv])
                cur_prv=prv[cur_prv];
            if(str[cur_prv]=='(')
                matched[cur_prv]=matched[next]=1;
            else 
            {
                insert_before('(',next);
                matched[cnt]=matched[next]=1;
            }
        }
        else if (str[next] == ']')
        {
            int cur_prv=prv[next];
            while(cur_prv!=-1 && matched[cur_prv])
                cur_prv=prv[cur_prv];
            if(str[cur_prv]=='[')
                matched[cur_prv]=matched[next]=1;
            else 
            {
                insert_before('[',next);
                matched[cnt]=matched[next]=1;
            }
        }
        next = nxt[next];
    }
    next = from;
    while (next != to)
    {
        if (matched[next])
        {
            next = nxt[next];
            continue;
        }
        if (str[next] == '(')
        {
            matched[next] = true;
            insert_after(')', next);
            matched[cnt] = true;
        }
        else if (str[next] == '[')
        {
            matched[next] = true;
            insert_after(']', next);
            matched[cnt] = true;
        }
        next = nxt[next];
    }
}
int main()
{
    memset(nxt, -1, sizeof(nxt));
    memset(prv, -1, sizeof(prv));
    memset(matched, 0, sizeof(matched));
    string con;
    cin >> con;
    for (int i = 0; i < con.size(); i++)
    {
        nxt[cnt] = cnt + 1;
        prv[cnt + 1] = cnt;
        str[++cnt] = con[i];
    }
    fix(1, -1);
    int n = nxt[0];
    while (n != -1)
    {
        putchar(str[n]);
        n = nxt[n];
    }
    putchar('\n');
    return 0;
}