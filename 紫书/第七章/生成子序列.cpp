#include <iostream>
#include <string>
void print_subset(int n, int* A,int *B ,int cur)
{
	for (int i = 0; i < cur; i++)
	{
		std::cout << A[i];
	}
	std::cout << std::endl;
	int pos = 0;
	for (int i = cur;i < n; i++)
	if(cur==0||A[cur-1]<B[i]){
		A[cur] = B[i];
		print_subset(n, A, B,cur + 1);
		for (int j = cur+1; j < n; j++)
			A[j] = 0;
	}
}

int main()
{
	int n;
	std::cin >> n;
	using namespace std;
	int* ache = new int[n];
	int* sets = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> sets[i];
	}
	print_subset(n, ache, sets, 0);
	return 0;
}