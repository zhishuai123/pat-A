#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
bool flag = false;
void post_order(vector<pair<int, int>>& tree, int root)
{
	if (root == 0)
		return;
	post_order(tree, tree[root].first);
	post_order(tree, tree[root].second);
	if (flag == true)
		cout << ' ';
	cout << root;
	flag = true;
}
int main()
{
	int num, root, tem = 0;
	cin >> num;
	vector<pair<int, int>> tree(num + 1);
	stack<int> s;
	vector<pair<string, int>>input(num * 2);
	for (int i = 0; i < 2 * num; i++)
	{
		cin >> input[i].first;
		if (input[i].first == "Push")
			cin >> input[i].second;
	}
	s.push(input[0].second);
	root = input[0].second;
	for (int i = 1; i < num * 2; i++)
	{
		if (input[i].first == "Push")
		{
			if (input[i - 1].first == "Push")
			{
				tree[s.top()].first = input[i].second;
				s.push(input[i].second);
			}
			else
			{
				tree[tem].second = input[i].second;
				s.push(input[i].second);
			}
		}
		else
		{
			tem = s.top();
			s.pop();
		}
	}
	post_order(tree, root);
	return 0;
}