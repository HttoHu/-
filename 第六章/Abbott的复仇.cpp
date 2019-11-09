#define function 
#include <iostream>
#define program int
#define main main()
class merdog_io
{
public:
	int input_int()
	{
		int ret;
		std::cin >> ret;
		return ret;
	}
	template<typename _Ty>
	void cout(_Ty t)
	{
		std::cout << t;
	}
	template<typename _T1, typename ..._Ty>
	void cout(_T1 arg0, _Ty... args)
	{
		cout(arg0);
		cout(args...);
	}
}mstd;
#define std mstd
#define elif else if

function bool is_prime(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i==0)
			return false;
	}
	return true;
}
int n;
bool is_p[1000] = { true };
int arr[100];
int vis[100] = { 0 };
function void set_prime()
{
	for (int i = 2; i < 1000; i += 1)
	{
		is_p[i] = is_prime(i);
	}
}
function void dfs(int cur)
{
	if (cur == n && is_p[arr[0] + arr[n - 1]])
	{
		for (int i = 0; i < n; i += 1)
		{
			std.cout(arr[i], ' ');
		}
		std.cout('\n');
	}
	else for (int i = 2; i <= n; i += 1)
	{
		if (!vis[i] && is_p[arr[cur-1] + i])
		{
			arr[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}
program main
{
	arr[0] = 1;
	n = std.input_int();
	set_prime();
	dfs(1);
}