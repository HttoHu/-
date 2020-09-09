#include <iostream>
#include <vector>
#include <algorithm>
int gcd(int x,int y)
{
	if (!y)
	{
		return x;
	}
	return gcd(y, x % y);
}
void solve(int n)
{
	for (int i = n; i <= n * 2; i++)
	{
		//feng mu
		int a = i * n;
		// fengzi  
		int b = i - n;
		int t = gcd(a, b);
		a /= t;
		b /= t;
		if (b == 1)
		{
			std::cout << "1/" << n << "=" << "1/" << a << "+1/" << i<<std::endl;
		}
	}
}
int main()
{
	int k;
	std::cin >> k;
	solve(k);
	return 0;
}