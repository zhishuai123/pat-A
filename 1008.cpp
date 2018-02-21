#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<int> list(num);
	for (int i = 0; i < num; i++)
		cin >> list[i];
	for (int i = num - 1; i > 0; i--)
		list[i] -= list[i - 1];
	int sum = 0;
	for (const auto& a : list)
		sum += a > 0 ? a * 6 : a*(-4);
	cout << sum + 5 * num;
	return 0;
}