#include <iostream>
#include <cstdio>
#include <algorithm>
template<typename T>
void quick_sort(T *s, T *e)
{
    int n = e - s;
    if (e - s <= 1)
        return;
    std::swap(s[0], s[n / 2]);
    int pivot = 0;
    for (int i = 1; i < n; i++)
        if (s[i] < s[0])
            std::swap(s[i], s[++pivot]);
    std::swap(s[pivot], s[0]);
    quick_sort(s, s + pivot);
    quick_sort(s + pivot + 1, e);
}
const int maxn = 100005;
int arr[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    quick_sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}