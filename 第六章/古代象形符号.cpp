/*
抄写一遍: https://blog.csdn.net/richenyunqi/article/details/
基本思路:
1. 将十六进制的图转换成二进制的图，1表示黑色，0表示白色
2. 给图的外围加一层白色(0)的外壳， 然后从(0,0)开始深搜一遍0的连通块，并将每个点标记成标记成2
3. 利用ans来表示白洞的个数，初始化为0。经过上一步操作后剩下的0全是字符内的洞了，然后开始扫描并深搜图中为1的点，标记成3，同时，若扫描到的1点旁边有0点，则深搜0的连通块，标记成2，并递增ans。当深度优先搜索结束时，ans即为白洞个数

*/
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<char,string> toBinary ={
    {'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},
    {'4',"0100"}, {'5',"0101"}, {'6',"0110"}, {'7',"0111"},
    {'8',"1000"}, {'9',"1001"}, {'a',"1010"}, {'b',"1011"},
    {'c',"1100"}, {'d',"1101"}, {'e',"1110"}, {'f',"1111"}
};
unordered_map<int,char>toAns={{1,'A'},{3,']'},{5,'D'},{4,'S'},{0,'W'},{2,'K'}};
int H,W,direction[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
vector<string>graph;
void dfs(int i,int j,char c,int &ans){
    graph[i][j]=char(c+2);
    for(int k=0;k<4;k++)
    {
        int ii=i+direction[k][0],jj=j+direction[k][1];
        if(ii>=0&&ii<graph.size()&&jj>=0;jj<graph[i].size()){
            if(c=='1'&&graph[ii][jj]=='0'){
                ++ans;
                dfs(ii,jj,'0',ans);
            }
            if(graph[ii][jj]==c)
                dfs(ii,jj,c,ans);
        }
    }
}
int main(){
    for(int ii=1;~scanf("%d%d*c",&H,&W)&&H!=0;++ii){
        graph.resize(H+2);
        graph.front()=string(W*4+2,'0');
        for(int i=1;i<H;i++){
            graph[i]='0';
            string s;
            getline(cin,s);
            for(auto c:s)
                graph[i]+=toBinary[c];
            graph[i]+="0";
        }
        graph.back()=string(W*4+2,'0');
        int ans=0;
        string result="";
        dfs(0,0,'0',ans);
        for(int i=0;i<graph.size();i++)
            for(int j=0;j<graph[i].size();j++){
                if(graph[i][j]=='1'){
                    ans=0;
                    dfs(i,j,'1',ans);
                    result+=toAns[ans];
                }
            }
        sort(result.begin(),result.end());
        printf("Case %d: &s\n",ii,result.c_str());
    }
}