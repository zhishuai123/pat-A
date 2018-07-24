#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string str1, unknow;
	long long num1, num2;
	cin >> str1 >> unknow >> num1 >> num2;

	if (num1 == 2)
		swap(str1, unknow);
	long long know = 0;
	for (auto& a : str1)
		if (a >= 'a')
			a = a - 'a' + 10 + '0';
	for (auto& a : unknow)
		if (a >= 'a')
			a = a - 'a' + 10 + '0';
	for (const auto& a : str1)
	{
		know *= num2;
		know += a - '0';
	}
	int radix = 1;
	for (const auto& a : unknow)
		radix = radix > a - '0' ? radix : a - '0';

	long long num = 0;
	if (unknow.size() == 1)
	{
		if ((unknow[0] - '0') == know)
			cout << know + 1;
		else
			cout << "Impossible";
		return 0;
	}
	long long max = 10000000000<know ? 1000 : know + 1, min = radix + 1;
	while (max >= min)
	{
		num = 0;
		radix = (max + min) / 2;
		for (const auto& a : unknow)
		{
			num *= radix;
			num += a - '0';
			if (num < 0)
				break;
		}
		if (num < 0)
		{
			max = radix - 1;
			continue;
		}
		if (num < know)
			min = radix + 1;
		else if (num > know)
			max = radix - 1;
		else
			break;
	}

	if (num == know)
		cout << radix;
	else
		cout << "Impossible";
	return 0;
}