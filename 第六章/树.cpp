/*
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int best = 0;
int best_sum = 1000000000;
struct Tree
{
	Tree(Tree* l, Tree* r, int v) :left(l), right(r), value(v) {}
	Tree* left;
	Tree* right;
	int value;
	void set_min_sum(int sum)
	{
		sum += value;
		if (left == nullptr && right == nullptr)
		{
			if (sum < best_sum || (sum == best_sum && value < best))
			{
				best = value;
				best_sum = sum;
			}
		}
		if(right)
			right->set_min_sum(sum);
		if(left)
			left->set_min_sum(sum);

	}
	~Tree()
	{
		if (left)
			delete left;
		if (right)
			delete right;
	}
};
Tree* build_tree(std::vector<int>& in_order,int i_s,int i_e, std::vector<int>& post_order,int p_s,int p_e)
{
	if (i_s == i_e)
	{
		return new Tree(nullptr, nullptr, in_order[i_s]);
	}
	if (i_s > i_e)
		return nullptr;
	int root_v = post_order[p_e];
	int start = i_s;
	while (in_order[start] != root_v)
		start++;
	auto left = build_tree(in_order, i_s, start - 1, post_order,i_s,start-1);
	auto right = build_tree(in_order, start + 1, i_e, post_order, start, p_e - 1);
	return new Tree(left, right, root_v);
}
int main()
{
	std::vector<int>result;
	std::vector<int> in_vec;
	std::vector<int> post_vec;
	std::string first_line,second_line;
	std::getline( std::cin,first_line);
	std::getline(std::cin, second_line);
	std::stringstream ss(first_line);
	int tmp = 0;
	while (ss >> tmp)
	{
		in_vec.push_back(tmp);
	}
	std::stringstream ss2(second_line);
	while (ss2 >> tmp)
	{
		post_vec.push_back(tmp);
	}
	auto tree=build_tree(in_vec, 0, in_vec.size() - 1, post_vec, 0, post_vec.size() - 1);
	tree->set_min_sum(0);
	result.push_back(best);
	for (auto a : result)
		std::cout << a << std::endl;
	while (1)
		std::cin.get();
	return 0;
}