#include <iostream>
#include <vector>
bool is_prime(int x)
{
	for (int i = 2; i*i <= x; i ++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

std::vector<bool>is_p(1000,0);
void set_prime_table()
{
	is_p[0] = false;
	is_p[1] = false;
	is_p[2] = true;
	for (int i = 3; i < 1000; i++)
	{
		is_p[i] = is_prime(i);
	}
}
std::vector<int> arr;
std::vector<int> vis(100,0);
int n;
void dfs(int cur)
{
	if (cur == n&&is_p[arr[0]+arr[n-1]])
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]&&is_p[i+arr[cur-1]])
		{
			arr[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	std::cin >> n;
	arr.resize(n);
	set_prime_table();
	arr[0] = 1;
	dfs(1);
	return 0;
}