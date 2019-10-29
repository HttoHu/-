/*
6
4 2
3 4
10 1
2 2
8 128
16 12345
-1
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int visit_tree(std::vector<bool>& tree, int no)
{
	// test buttom
	if (no >= tree.size() / 2)
	{
		return no;
	}
	if (tree[no])
	{
		tree[no] = !tree[no];
		return visit_tree(tree, no * 2 + 1);
	}
	tree[no] = !tree[no];
	return visit_tree(tree, no * 2);
}
int ball_dropping()
{
	std::vector<int>result_vec;
	int case_count;
	cin >> case_count;
	int first_argue = 0;
	int secon_argue = 0;
	while (true)
	{
		cin >> first_argue;
		if (first_argue == -1)
			break;
		cin >> secon_argue;
		// reserve one
		std::vector<bool> tree(std::pow(2, first_argue),false);
		for (int i = 0; i < secon_argue-1; i++)
		{
			visit_tree(tree, 1);
		}
		result_vec.push_back(visit_tree(tree, 1));
	}
	for (auto a : result_vec)
		std::cout << a << std::endl;
	return 0;
}