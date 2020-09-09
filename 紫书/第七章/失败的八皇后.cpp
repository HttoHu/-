/*8皇后问题*/
#include <iostream>
#include <vector>
#include <set>
int map[10][10] = { 0 };
std::set<int> line_set;
std::set<int> row_set;
std::set<int> xpy_set;
std::set<int>xmy_set;
bool exists(int i, int j)
{
	auto result = xpy_set.find(j + i);
	auto result2 = xmy_set.find(i - j);
	if (result == xpy_set.end() && result2 == xmy_set.end())
		return true;
	return false;
}
using solution = std::vector<std::pair<int, int>>;
std::vector<std::pair<int, int>> cur_king_postion;
std::vector<solution> solutions;
void solve(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (line_set.find(i) == line_set.end())
		{
			for (int j = 0; j < n; j++)
			{
				if (row_set.find(j) == row_set.end())
				{
					if (exists(i, j))
					{ 
						cur_king_postion.push_back({ i,j });
						line_set.insert(i);
						row_set.insert(j);
						xpy_set.insert(i + j);
						xmy_set.insert(i - j);
						if (cur_king_postion.size() == n)
							return;
						break;
					}

				}
			}
		}
	}
}
int main()
{
	solve(8);
	for (auto& a : cur_king_postion)
	{
		std::cout << "(" << a.first << "," << a.second << ")"<<std::endl;
	}
	return 0;
}