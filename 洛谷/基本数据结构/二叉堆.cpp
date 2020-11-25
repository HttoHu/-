#include <iostream>
#include <vector>
using namespace std;
const int maxn=2000005;
template<typename T>
class Heap{
    public:
        Heap()
        {

        }
        void push(T ele)
        {
            data[++size]=ele;
            auto cur=size;
            while(cur > 1)
            {
                auto par=cur/2;
                if(data[cur] >= data[par])
                    return;
                swap(data[cur],data[par]);
                cur=par;
            }
        }
        void pop()
        {
            data[1]=data[size--];
            auto cur=1;
            while(cur*2 <=size)
            {
                auto child=cur*2;
                // select the min child.
                if(child < size && data[child+1] < data[child] )
                    child++;
                if(data[child] >= data[cur])
                    return;
                swap(data[cur],data[child]);
                cur=child;
            }
        }
        T& top(){
            return data[1]; 
        }
    private:
        T data[maxn];
        size_t size=0;
};
// op 1: push x
// op 2: top
// op 3: pop
Heap<int> q;
int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int ins;
        cin>>ins;
        if(ins==1)
        {
            int x;
            cin>>x;
            q.push(x);
        }
        else if(ins==2)
            cout<<q.top()<<endl;
        else 
            q.pop();
    }
    return 0;
}