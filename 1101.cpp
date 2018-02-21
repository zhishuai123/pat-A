#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<int> input(num);
	vector<pair<int, int>> maxAndMin(num, { -1,1000000001 });
	for (auto& a : input)
		cin >> a;
	maxAndMin[0].first = input[0];
	maxAndMin[num - 1].second = input[num - 1];
	for (int i = 1; i < num; i++)
		maxAndMin[i].first = maxAndMin[i - 1].first > input[i] ? maxAndMin[i - 1].first : input[i];
	for (int i = num - 2; i >= 0; i--)
		maxAndMin[i].second = maxAndMin[i + 1].second < input[i] ? maxAndMin[i + 1].second : input[i];
	vector<int> target;
	for (int i = 0; i < num; i++)
		if (input[i] <= maxAndMin[i].second&&input[i] >= maxAndMin[i].first)
			target.push_back(input[i]);
	cout << target.size() << endl;
	if (target.size() == 0)
	{
		cout << endl;
		return 0;
	}
	cout << target[0];
	for (int i = 1; i < target.size(); i++)
		cout << ' ' << target[i];
	return 0;
}