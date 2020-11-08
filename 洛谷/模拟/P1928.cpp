#include <iostream>
#include <string>
using namespace std;
string content;
string parse_unit(int &i);
string build_str(int &i)
{
    string ret;
    while (content[i] != ']' && i < content.size())
        if (content[i] == '[')
            ret += parse_unit(i);
        else
            ret += content[i++];
    return ret;
}
string parse_unit(int &i)
{
    string ret;
    // skip [
    i++;
    int num = 0;
    while (isdigit(content[i]))
    {
        num *= 10;
        num += content[i++] - '0';
    }
    string tmp = build_str(i);
    for (int i = 0; i < num; i++)
        ret += tmp;
    // skip ]
    i++;
    return ret;
}
int main()
{
    getline(cin, content);
    int i = 0;
    std::cout << build_str(i);
    return 0;
}