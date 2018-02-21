#include<iostream>
#include<map>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int num1, num2, num3;
	cin >> num1 >> num2;
	map<int, int> m;
	for (int i = 0; i < num1*num2; i++)
	{
		cin >> num3;
		m[num3]++;
	}
	for (auto &a : m)
		if (a.second > num2*num1 / 2)
		{
			cout << a.first;
			return 0;
		}
	return 0;
}