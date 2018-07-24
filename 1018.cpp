#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
void dij(vector<vector<int>> graph, vector<vector<int>>&target, int start, int end)
{
	vector<bool> over(graph.size(), false);
	vector<int> min_path(graph.size(), -1);
	over[0] = true;
	min_path[0] = 0;
	bool flag = false;
	while (flag == false)
	{
		flag = true;
		int min = 2147483647, min_start, min_end;
		for (int i = 0; i < over.size(); i++)
		{
			if (over[i] == true)
			{
				for (int j = 0; j < graph.size(); j++)
				{
					if (graph[i][j] != -1 && min > graph[i][j] + min_path[i])
					{
						min = graph[i][j] + min_path[i];
						min_start = i, min_end = j;
					}
				}
			}
		}
		graph[min_start][min_end] = -1;
		graph[min_end][min_start] = -1;
		if (min_path[min_end] == -1 || min == min_path[min_end])
			target[min_start].push_back(min_end);
		if (min_path[min_end] == -1)
			min_path[min_end] = min;
		over[min_end] = true;
		for (int i = 0; i < graph.size(); i++)
			flag &= graph[i][end] == -1;
	}
}
void listToPath(vector<vector<int>>&list, vector<vector<int>>& target, int start, int end, vector<int>tem)
{
	tem.push_back(start);
	if (start == end)
	{
		target.push_back(tem);
		return;
	}
	for (int i = 0; i < list[start].size(); i++)
		listToPath(list, target, list[start][i], end, tem);
}
bool cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.first == b.first)
		return a.second<b.second;
	return a.first < b.first;
}
int main()
{
	int perfect_num, station_num, target_num, edge_num;
	cin >> perfect_num >> station_num >> target_num >> edge_num;
	vector<int> station(station_num);
	vector<vector<int>> graph(station_num + 1, vector<int>(station_num + 1, -1));
	vector<vector<int>> target(station_num + 1);
	for (int i = 0; i < station_num; i++)
		cin >> station[i];
	int tem1, tem2;
	for (int i = 0; i < edge_num; i++)
	{
		cin >> tem1 >> tem2;
		cin >> graph[tem1][tem2];
		graph[tem2][tem1] = graph[tem1][tem2];
	}
	dij(graph, target, 0, target_num);
	vector<vector<int>> path;
	listToPath(target, path, 0, target_num, vector<int>());
	vector<pair<int, int>> bikes(path.size());
	vector<vector<int>> state(path);
	for (auto& a : state)
		for (auto& b : a)
			b = 0;
	for (int i = 0; i < path.size(); i++)
	{
		int min_bike = 2147483647;
		for (int j = 1; j < path[i].size(); j++)
		{
			state[i][j] = state[i][j - 1] + station[path[i][j] - 1] - perfect_num / 2;
			min_bike = min_bike < state[i][j] ? min_bike : state[i][j];
		}
		bikes[i].first = min_bike < 0 ? -min_bike : 0;
		bikes[i].second = *state[i].rbegin() + bikes[i].first;
	}
	int min_index = 0;
	for (int i = 1; i < bikes.size(); i++)
		min_index = cmp(bikes[min_index], bikes[i]) ? min_index : i;
	cout << bikes[min_index].first << ' ';
	cout << path[min_index][0];
	for (int i = 1; i < path[min_index].size(); i++)
		cout << "->" << path[min_index][i];
	cout << ' ' << bikes[min_index].second;
	return 0;
}