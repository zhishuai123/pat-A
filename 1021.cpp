#include<iostream>
#include<vector>
using namespace std;
bool dfs(vector<vector<int>>& list, int start, vector<bool>& flag)
{
	if (flag[start] == true)
		return false;
	flag[start] = true;
	for (int i = 0; i < list[start].size(); i++)
		dfs(list, list[start][i], flag);
	return true;
}
int find_dfs(vector<vector<int>>& list, int start, vector<bool>& flag)
{
	int x = 0;
	for (int i = 0; i < list[start].size(); i++)
		if (flag[list[start][i]] == false)
			x++;
	if (x == 0)
		return 1;
	flag[start] = true;
	int max = 0, tem;
	for (int i = 0; i < list[start].size(); i++)
	{
		if (flag[list[start][i]] == false)
		{
			tem = find_dfs(list, list[start][i], flag);
			max = max > tem ? max : tem;
		}
	}
	return max + 1;
}
int main()
{
	int num;
	cin >> num;
	vector<vector<int>> list(num);
	int tem1, tem2;
	for (int i = 0; i < num - 1; i++)
	{
		cin >> tem1 >> tem2;
		list[tem1 - 1].push_back(tem2 - 1);
		list[tem2 - 1].push_back(tem1 - 1);
	}
	int count = 0;
	vector<bool> flag(num, false);
	for (int i = 0; i < num; i++)
		if (dfs(list, i, flag) == true)
			count++;
	if (count > 1)
	{
		cout << "Error: " << count << " components";
		return 0;
	}
	vector<int> target;
	int max = 0, tem;
	for (int i = 0; i < num; i++)
	{
		flag.assign(num, false);
		tem = find_dfs(list, i, flag);
		if (max < tem)
		{
			max = tem;
			target.clear();
			target.push_back(i);
		}
		else if (max == tem)
			target.push_back(i);
	}
	for (auto& a : target)
		cout << a + 1 << endl;
	return 0;
}