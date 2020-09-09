#include <iostream>
using namespace std;
void print_subset(int n,int s)
{
	for (int i = 0; i < n; i++)
	{
		if (s & (1 << i))
			cout << i+1;
	}
	cout << endl;

}
int main()
{

	int n;
	cin >> n;
	//if n is 3 i from 001 to 111
	/* 000 001 010 011 100 101
	*/
	for (int i = 0; i < (1<<n); i++)
	{
		print_subset(n, i);
	}
	return 0;
}