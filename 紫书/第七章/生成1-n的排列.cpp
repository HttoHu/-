#include <iostream>
#include<string>
void print_premutation(int n, int* A, int cur)
{
	if (n == cur)
	{ 
		for (int i = 0; i < n; i++)
			std::cout << A[i];
		std::cout << std::endl;
	}
	else for (int i = 1; i <= n; i++)
	{
		bool ok = true;
		for (int j = 0; j < cur; j++)
		{
			if (A[j] == i)
				ok = false;
		}
		if (ok)
		{
			A[cur] = i;
			print_premutation(n, A, cur + 1);
		}
	}
}
int main()
{
	int a;
	std::cin >> a;
	int* arr = new int[a];
	print_premutation(a, arr, 0);
	return 0;
}