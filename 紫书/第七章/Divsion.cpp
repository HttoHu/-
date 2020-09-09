//Divsion
/*
example:
62
79546 / 01283 =62
94736 / 01528 =62
*/
#include <iostream>
#include <string>
#include <set>
std::string to_string(int tmp)
{
	std::string ret;
	if (tmp < 0)
	{
		ret += '-';
		tmp = -tmp;
	}
	while (tmp != 0)
	{
		int this_bit = tmp % 10;
		ret = std::string(1, (char)(this_bit + 48)) + ret;
		tmp /= 10;
	}
	return ret;
}
bool is_all_covered(std::string str)
{
	std::set<char> s;
	for (int i = 0; i < str.size(); i++)
	{
		s.insert(str[i]);
	}
	return s.size()== 10;
}
std::string add_zero_prefix(std::string tmp, int sz)
{
	if (tmp.size() >= sz)
		return tmp;
	int n =  sz-tmp.size();
	std::string t (n, '0');
	return t + tmp;
}
int main()
{
	int tmp = 0;
	std::cin >> tmp;
	for (int i = 0; i < 99999; i++)
	{
		if (i % tmp == 0)
		{
			std::string str = add_zero_prefix(to_string(i),5);

			std::string str2 = add_zero_prefix(to_string(i / tmp),5);
			if (is_all_covered(str+str2))
				std::cout << str << " / " << str2 << "=" << tmp << std::endl;
		}
	}
	return 0;
}