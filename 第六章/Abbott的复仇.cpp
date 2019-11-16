#include <iostream>
#include <vector>
int cnt=0;
int n;
int L;
int S[100];
int dfs(int cur)
{
	if (cnt++ == n)
	{
		for (int i = 0; i < cur; i++)
		{
			std::cout << (char)('A' + S[i]);
		}
		std::cout << std::endl;
		return 0;
	}
	for (int i = 0; i < L; i++)
	{
		S[cur] = i;
		bool ok = true;
		for (int j = 1; j * 2 <= cur + 1; j++)
		{
			int equal = 1;
			for (int k = 0; k < j; k++)
			{
				if (S[cur - k] != S[cur - k - j])
				{
					equal = 0;
					break;
				}
			}
			if (equal)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			if (!dfs(cur + 1))
				return 0;
		}
	}
	return 1;
}
int main()
{
	std::cin >> n;
	std::cin >> L;
	dfs(0);
	return 0;
}
