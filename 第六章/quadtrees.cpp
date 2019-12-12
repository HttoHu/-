/*
3
ppeeefpffeefe
pefepeefe
peeef
peefe
peeef
peepefefe 
*/
#include <iostream>
#include <string>

const int len=1024;
const int maxn=1024+10;
char s[maxn];
int buf[len][len],cnt;

//我又种树了，种了一半，偷偷的看了例题答案😭，我好菜.
//(r,c), w是边长
// 2 1
// 3 4
void draw(const char *s,int &p,int r,int c,int w){
    char ch=s[p++];
    if(ch=='p')
    {
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2 );
        draw(s,p,r+w/2,c+w/2,w/2);
    }
    else if(ch=='f'){
        for(int i=r;i<w+r;i++)
        {
            for(int j=c;j<w+c;j++)
            {
                if(buf[i][j]==0)
                {
                    buf[i][j]=1;
                    cnt++;
                }
            }
        }
    }
}
int results[10];
int main()
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        cnt=0;
        memset(buf,0,sizeof(buf));
        scanf("%s",s);
        int cur=0;
        draw(s,cur,0,0,len);
        scanf("%s",s);
        cur=0;
        draw(s,cur,0,0,len);
        results[i]=cnt;
    }
    for(int i=0;i<n;i++)
    {
        std::cout<<"There are "<<results[i]<<" black pixels.\n";
    }
    return 0;
}