#include <stdio.h>
template<int N,typename T>
int acount(const T (&arr)[N])
{
    return sizeof(arr)/sizeof(T);
}
int main()
{
    int arr[45];
    printf("%d",acount(arr));
    return 0;
}