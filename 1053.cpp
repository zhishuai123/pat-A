#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
int find_path(vector<vector<int>>& tree, vector<vector<int>>& path, vector<int>& weight, int sum, int root)
{
	if (tree[root].size() == 0)
		if (weight[root] == sum)
			return 1;
		else
			return 0;
	int num1 = 0, num2 = 0;
	for (int i = 0; i < tree[root].size(); i++)
	{
		if (num2 = find_path(tree, path, weight, sum - weight[root], tree[root][i]))
		{
			num1 += num2;
			path[root].push_back(tree[root][i]);
		}
	}
	return num1;
}
vector<int> f(vector<vector<int>>& path, vector<vector<int>>& target, vector<int>&weight, int root)
{
	if (path[root].size() == 0)
	{
		for (int i = 0; i < target.size(); i++)
			if (target[i].size() == 0)
			{
				target[i].push_back(weight[root]);
				return { i };
			}
	}
	vector<int> tem1, tem2;
	for (int i = 0; i < path[root].size(); i++)
	{
		tem2 = f(path, target, weight, path[root][i]);
		tem1.insert(tem1.end(), tem2.begin(), tem2.end());
	}
	for (const auto& a : tem1)
		target[a].push_back(weight[root]);
	return tem1;
}
vector<int> weight;
struct mycomp {
	bool operator()(int a, int b) {
		return weight[a] > weight[b];
	}
};
int main()
{
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	weight.assign(num1, 0);
	for (int i = 0; i < num1; i++)
		cin >> weight[i];
	vector<vector<int>> tree(num1);
	int leaf, root;
	for (int i = num2; i > 0; i--)
	{
		cin >> root;
		cin >> num2;
		for (int i = 0; i < num2; i++)
		{
			cin >> leaf;
			tree[root].push_back(leaf);
		}
	}
	vector<vector<int>> path(num1);
	int x = find_path(tree, path, weight, num3, 0);
	vector<vector<int>> target(x);

	for (int i = 0; i < num1; i++)
	{
		if (path[i].size() != 0)
			sort(path[i].begin(), path[i].end(), mycomp());
	}
	f(path, target, weight, 0);
	for (auto i = target[0].rbegin(); i != target[0].rend() - 1; i++)
		cout << *i << ' ';
	cout << *(target[0].rend() - 1);
	for (int i = 1; i<target.size(); i++)
	{
		cout << endl;
		for (auto j = target[i].rbegin(); j != target[i].rend() - 1; j++)
			cout << *j << ' ';
		cout << *(target[i].rend() - 1);
	}
	return 0;
}