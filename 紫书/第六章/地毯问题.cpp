//ตุฬบฮสฬโ
#include <iostream>
#include <list>
#include <vector>
struct Blanket
{
	Blanket(int _x, int _y, int _len, int _height) :x(_x), y(_y), length(_len), height(_height) {}
	bool in_range(int a, int b)
	{
		return a >= x && a <= x + length && b >= y && b <= y + height;
	}
	int x;
	int y;
	int length;
	int height;
};
std::vector<Blanket> bl_vec;
void input_new_line()
{
	int a, b, g, k;
	std::cin >> a >> b >> g >> k;
	bl_vec.push_back(Blanket(a, b, g, k));
}
int driver()
{
	int n = 0;
	std::cin >> n;
	bl_vec.reserve(n);
	for (int i = 0; i < n; i++)
	{
		input_new_line();
	}
	int x, y;
	std::cin >> x >> y;
	for (int i = n; i !=0; i--)
	{
		if (bl_vec[i-1].in_range(x, y))
			return i;
	}
	return -1;
}