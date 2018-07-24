#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long num, tem;
	vector<long long> input;
	for (int i = 0; i < 2; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> tem;
			input.push_back(tem);
		}
	}
	sort(input.begin(), input.end());
	cout << input[(input.size() - 1) / 2];
	return 0;
}