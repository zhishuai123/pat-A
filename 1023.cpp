#include<iostream>
#include<string>
using namespace std;
int main()
{
	int map[10] = {};
	string num;
	cin >> num;
	for (const auto &a : num)
		map[a - '0']++;
	int i = 1;
	if (num[0] - '0' >= 5)
	{
		num[0] = (num[0] - '0') * 2 - 10 + '0';
		num = "1" + num;
		i++;
	}
	else
		num[0] = num[0] * 2 - '0';
	for (; i < num.size(); i++)
	{
		if (num[i] - '0' >= 5)
		{
			num[i] = (num[i] - '0') * 2 - 10 + '0';
			num[i - 1]++;
		}
		else
			num[i] = num[i] * 2 - '0';
	}
	for (const auto &a : num)
		map[a - '0']--;
	for (const auto &a : map)
		if (a != 0)
		{
			cout << "No" << endl;
			cout << num;
			return 0;
		}
	cout << "Yes" << endl;;
	cout << num;
	return 0;
}