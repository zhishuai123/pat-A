#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define right first
#define left second
using namespace std;
void in_order(vector<pair<int, int>>&tree, int node, vector<int>&target)
{
	if (node == -1)
		return;
	in_order(tree, tree[node].left, target);
	target.push_back(node);
	in_order(tree, tree[node].right, target);
}
int main()
{
	int num;
	cin >> num;
	vector<pair<int, int>> tree(num, { -1,-1 });
	vector<bool> nodeIsRoot(num, true);
	string str1, str2;
	for (int i = 0; i < num; i++)
	{
		cin >> str1 >> str2;
		if (str1 != "-")
		{
			tree[i].right = stoi(str1);
			nodeIsRoot[tree[i].right] = false;
		}
		if (str2 != "-")
		{
			tree[i].left = stoi(str2);
			nodeIsRoot[tree[i].left] = false;
		}
	}
	int root;
	for (root = 0; root < num&&nodeIsRoot[root] != true; root++);
	queue<int> q;
	cout << root;
	q.push(tree[root].left);
	q.push(tree[root].right);
	while (!q.empty())
	{
		if (q.front() != -1)
		{
			q.push(tree[q.front()].left);
			q.push(tree[q.front()].right);
			cout << ' ' << q.front();
		}
		q.pop();
	}
	vector<int> target;
	in_order(tree, root, target);
	cout << endl;
	cout << target[0];
	for (int i = 1; i < num; i++)
		cout << ' ' << target[i];
	return 0;
}