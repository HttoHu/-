#include <iostream>
using namespace std;
void print_subset(int n, int* A, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i])
				std::cout << i + 1;
		}
		cout << endl;
		return;
	}

	A[cur] = 1;
	print_subset(n, A, cur + 1);
	A[cur] = 0;
	print_subset(n, A, cur + 1);

}
int main()
{

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	print_subset(n, arr, 0);
	return 0;
}