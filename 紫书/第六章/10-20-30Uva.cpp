#include <deque>
#include <string>
#include <iostream>
/*
    不知道哪里错了😭
*/
using namespace std;
deque<int> hand;
deque<int> piles[7];
void check_piles(int n)
{
    auto &a = piles[n];
    if (a.size() < 3)
        return;
    int p1, p2, p3;
    while (a.size()>=3)
    {
        p1 = 0;
        p2 = a.size() - 1;
        p3 = 1;
        int sum = a[p1] + a[p2] + a[p3];
        if (sum == 10 || sum == 20 || sum == 30)
        {
            hand.push_back(a[p1]);
            hand.push_back(a[p3]);
            hand.push_back(a[p2]);
            a.pop_front();
            a.pop_front();
            a.pop_back();
            continue;
        }
        p1 = 0;
        p2 = a.size() - 1;
        p3 = a.size() - 2;
        sum = a[p1] + a[p2] + a[p3];
        if (sum == 10 || sum == 20 || sum == 30)
        {
            hand.push_back(a[p1]);
            hand.push_back(a[p3]);
            hand.push_back(a[p2]);
            a.pop_back();
            a.pop_front();
            a.pop_back();
            continue;
        }
        p1 = a.size() - 3;
        p2 = a.size() - 1;
        p3 = a.size() - 2;
        sum = a[p1] + a[p2] + a[p3];
        if (sum == 10 || sum == 20 || sum == 30)
        {
            hand.push_back(a[p1]);
            hand.push_back(a[p3]);
            hand.push_back(a[p2]);
            a.pop_back();
            a.pop_back();
            a.pop_back();
            continue;
        }
        break;
    }
}
int op_c=8;
void operate()
{
    if (hand.empty())
        return;
    for (int i = 0; i < 7; i++)
    {
        if (piles[i].empty())
        {
            continue;
        }
        piles[i].push_back(hand.front());
        hand.pop_front();
        check_piles(i);
        op_c++;
        if (hand.empty()||hand.size()==52)
            return;
    }
}
string process()
{
    for (int i = 0; i < 7; i++)
    {
        piles[i].push_back(hand.front());
        hand.pop_front();
    }
    while (true)
    {
        operate();
        if (hand.size() == 52)
        {
            return "Win : " + to_string(op_c);
        }
        if (hand.empty())
        {
            return "Loss : " + to_string(op_c);
        }
        if (op_c > 100000)
        {
            return "Draw : ";
        }
    }
}
string output;

int main()
{
    while (true)
    {
        int tmp;
        hand.clear();
        for (int i = 0; i < 7; i++)
        {
            piles[i].clear();
        }
        cin >> tmp;
        if (tmp == 0)
            break;
        hand.push_front(tmp);
        for (int i = 0; i < 51; i++)
        {
            cin >> tmp;
            hand.push_front(tmp);
        }
        output += process() + "\n";
    }
    cout << output;
    return 0;
}