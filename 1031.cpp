
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int	tem2 = str.size() % 3;
	int tem1 = str.size() / 3;
	if (tem2 == 0)
	{
		tem1--;
		tem2 += 3;
	}
	for (int i = 0, j = str.size() - 1; i < tem1; i++, j--)
	{
		cout << str[i];
		for (int i = 0; i < tem1 + tem2 - 2; i++)
			cout << ' ';
		cout << str[j] << endl;
	}
	for (int i = 0; i < tem1 + tem2; i++)
		cout << str[tem1 + i];
	return 0;
}