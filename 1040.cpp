
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	int max = 0, tem;
	int x, y;
	getline(cin, str);
	if (str.size() == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 1; i < str.size(); i++)
	{
		x = i - 1, y = i;
		tem = 0;
		while (x >= 0 && y != str.size() && str[x] == str[y])
		{
			tem += 2;
			x--;
			y++;
		}
		max = max > tem ? max : tem;
	}
	for (int i = 1; i < str.size(); i++)
	{
		x = i - 1, y = i + 1;
		tem = 1;
		while (x >= 0 && y != str.size() && str[x] == str[y])
		{
			tem += 2;
			x--;
			y++;
		}
		max = max > tem ? max : tem;
	}
	cout << max;
	return 0;
}