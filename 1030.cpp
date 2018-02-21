
#include<iostream>
#include<vector>
using namespace std;
void min_path(vector<vector<int>>& graph, int start, int end, vector<vector<int>>& path)
{
	path[start][0] = 0;
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

int main()
{
	int city_num = 0, highway_num = 0, start_city = 0, destination = 0;
	cin >> city_num >> highway_num >> start_city >> destination;

	if (city_num == 0 || highway_num == 0)
		return 0;

	vector<vector<int>> input(highway_num, { 0,0,0,0 });
	vector<int> tem(city_num, -1);
	vector<vector<int>> distance_graph(city_num, tem);
	vector<vector<int>> cost_graph(city_num, tem);
	
	vector<vector<int>> path_map(city_num);
	for (int i = 0; i < highway_num; i++)
		for (int j = 0; j < 4; j++)
			cin >> input[i][j];

	for (int i = 0; i < highway_num; i++)
	{
		distance_graph[input[i][1]][input[i][0]] = input[i][2];
		distance_graph[input[i][0]][input[i][1]] = input[i][2];
	}
	for (int i = 0; i < highway_num; i++)
	{
		cost_graph[input[i][1]][input[i][0]] = input[i][3];
		cost_graph[input[i][0]][input[i][1]] = input[i][3];
	}
	vector<vector<int>> distance_path(city_num, { -1 });
	vector<vector<int>> cost_path(city_num, { -1 });

	min_path(distance_graph, start_city, destination, distance_path);

	vector<vector<int>> min_dis_cost_graph(city_num, tem);

	for (int i=0;i<distance_path.size();i++)
	{
		for (int j = 1; j < distance_path[i].size(); j++)
			min_dis_cost_graph[i][distance_path[i][j]] = cost_graph[i][distance_path[i][j]];
	}

		min_path(min_dis_cost_graph, start_city, destination, cost_path);
		
	vector<int> path;
	int city = destination;
	while (city != start_city)
	{
		path.push_back(city);
		city = cost_path[city][1];
	}
	path.push_back(start_city);

	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << ' ';
	cout << distance_path[destination][0] << ' ';
	cout << cost_path[destination][0];
    return 0;
}