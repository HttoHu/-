#include <iostream>
#include<string>
// A是构建的数据都放到A中，P是原来的序列，我们现在要全排，每一次A要打印是都是P的一次排列
// 下面我们称A为缓冲区
void print_premutation(int n, int* A,int*P, int cur)
{
	if (n == cur)
	{ 
		for (int i = 0; i < n; i++)
			std::cout << A[i];
		std::cout << std::endl;
	}
	else for (int i = 0; i < n; i++)
	if(i==0||P[i]!=P[i-1]){
		int c1 = 0, c2 = 0;
		for (int j = 0; j < cur; j++)
		{
			if (A[j] == P[i])
				c1++;
		}
		for (int j = 0; j < n; j++)
		{
			if (P[i] == P[j])
				c2++;
		}
		if (c1 < c2)
		{
			// 我们在缓冲区的cur位置加上我们没有出现的当前值
			A[cur] = P[i];
			// 然后继续递归
			print_premutation(n, A,P, cur + 1);
		}
	}
}
int main()
{
	int a;
	std::cin >> a;
	int* arr = new int[a];
	int* arr2 = new int[a];
	for (int i = 0; i < a; i++)
	{ 
		arr[i] = 0;
		std::cin >> arr2[i];
	}
	print_premutation(a, arr,arr2, 0);
	return 0;
}