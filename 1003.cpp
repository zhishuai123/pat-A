
#include<iostream>
#include<vector>
using namespace std;
void min_path(vector<vector<int>>& graph, int start, int end, vector<vector<int>>& path)
{
	path[start][0] = 0;
	if (start == end)
		return;
	int min_start = -1, min_next = -1, min_distance = -1;
	int sum = 0;
	while (sum != -graph.size())
	{
		min_start = -1, min_next = -1, min_distance = -1;
		for (int city = 0; city < graph.size(); city++)
		{
			if (path[city][0] != -1)
			{
				for (int i = 0; i < graph.size(); i++)
				{
					if (graph[i][city] != -1 && (path[city][0] + graph[i][city] <= min_distance || min_distance == -1))
					{
						min_start = city;
						min_next = i;
						min_distance = graph[i][city] + path[city][0];
					}
				}
			}
		}
		graph[min_next][min_start] = -1;
		graph[min_start][min_next] = -1;

		if (path[min_next][0] == min_distance)
			path[min_next].push_back(min_start);
		else if (min_distance < path[min_next][0] || path[min_next][0] == -1)
		{
			path[min_next].clear();
			path[min_next].push_back(min_distance);
			path[min_next].push_back(min_start);
		}
		else if (min_distance > path[min_next][0] && min_next == end)
			break;
		sum = 0;
		for (int &num : graph[end])
			sum += num;
	}
}

pair<int, int> record(vector<vector<int>>& path, int start, int end, vector<int>& men_num)             //改到我绝望
{
	if (end == start)
		return { 1,men_num[end] };
	pair<int, int> tem = { 0,men_num[end] };
	int max = 0;
	for (int i = 1; i < path[end].size(); i++)
	{
		pair<int, int> tem1 = record(path, start, path[end][i], men_num);
		tem.first += tem1.first;
		max = tem1.second > max ? tem1.second : max;
	}
	return { tem.first,tem.second + max };
}
int main()
{
	int city_num, road_num, start, destination;
	cin >> city_num >> road_num >> start >> destination;
	vector<vector<int>> city_graph(city_num, vector<int>(city_num, -1));
	vector<int> men_num(city_num);
	int tem1, tem2, tem3;
	for (int i = 0; i < city_num; i++)
		cin >> men_num[i];
	for (int i = 0; i < road_num; i++)
	{
		cin >> tem1 >> tem2 >> tem3;
		city_graph[tem1][tem2] = tem3;
		city_graph[tem2][tem1] = tem3;
	}
	vector<vector<int>> path(city_num, { -1 });
	min_path(city_graph, start, destination, path);

	pair<int, int> tem = record(path, start, destination, men_num);
	cout << tem.first << ' ' << tem.second;
	return 0;
}