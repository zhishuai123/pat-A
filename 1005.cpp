#include<iostream>
#include<string>
int main()
{
	const std::string ENG[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int sum = 0;
	char ch = 0;
	while (std::cin.get(ch) && ch != '\n')
		sum += ch - '0';
	std::string str = std::to_string(sum);
	std::cout << ENG[str[0] - '0'];
	for (int i = 1; i < str.size(); i++)
		std::cout << ' ' << ENG[str[i] - '0'];
	return 0;
}