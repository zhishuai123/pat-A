
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	vector<vector<int>> tree(num1 + 1);
	int tem1, tem2, tem3;
	tree[0].assign(num1 + 1, 0);
	for (int i = 0; i < num2; i++)
	{
		cin >> tem1 >> tem2;
		for (int j = 0; j < tem2; j++)
		{
			cin >> tem3;
			tree[tem1].push_back(tem3);
		}
	}
	queue<int> q;
	q.push(1);
	tree[0][q.front()] = 1;
	while (!q.empty())
	{
		for (int i = 0; i < tree[q.front()].size(); i++)
		{
			q.push(tree[q.front()][i]);
			tree[0][tree[q.front()][i]] = tree[0][q.front()] + 1;
		}
		q.pop();
	}
	int max = 0;
	for (const auto& a : tree[0])
		max = max > a ? max : a;
	vector<int> target(max, 0);
	for (int i = 1; i < tree.size(); i++)
		if (tree[i].size() == 0)
			target[tree[0][i] - 1]++;
	cout << target[0];
	for (int i = 1; i < target.size(); i++)
		cout << ' ' << target[i];
	return 0;
}