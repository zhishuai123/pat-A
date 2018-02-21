#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool dfs(vector<vector<int>>& list, int city, vector<bool>& over)
{
	if (over[city] == false)
	{
		over[city] = true;
		for (int i = 0; i < list[city].size(); i++)
			dfs(list, list[city][i], over);
		return true;
	}
	return false;
}
int main()
{
	int num1, num2, num3, city1, city2;
	cin >> num1 >> num2 >> num3;
	vector<vector<int>> list(num1 + 1);
	for (int i = 0; i < num2; i++)
	{
		cin >> city1 >> city2;
		list[city1].push_back(city2);
		list[city2].push_back(city1);
	}
	vector<int> target(num3);
	for (int i = 0; i < num3; i++)
		cin >> target[i];
	vector<vector<int>> tem;
	vector<bool> over;
	int count;
	for (const auto& a : target)
	{
		over.assign(num1 + 1, false);
		tem = list;
		tem[a].clear();
		count = -1;
		for (int i = 1; i < num1 + 1; i++)
			if (i != a&&dfs(tem, i, over) == true)
				count++;
		cout << count << endl;
	}

	return 0;
}