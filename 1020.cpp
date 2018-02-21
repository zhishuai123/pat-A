#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int traversal(vector<int> post_order, vector<int> in_order, vector<vector<int>>& level_order)
{
	if (post_order.size() == 0)
		return -1;
	else if (post_order.size() == 1)
		return post_order[0];
	int i = 0;
	while (in_order[i] != *post_order.rbegin())
		i++;

	int tem1 = traversal(vector<int>(post_order.begin(), post_order.begin() + i), vector<int>(in_order.begin(), in_order.begin() + i), level_order);;
	int tem2 = traversal(vector<int>(post_order.begin() + i, post_order.end() - 1), vector<int>(in_order.begin() + i + 1, in_order.end()), level_order);;

	if (tem1 != -1)
		level_order[*post_order.rbegin()].push_back(tem1);
	if (tem2 != -1)
		level_order[*post_order.rbegin()].push_back(tem2);
	return *post_order.rbegin();
}
int main()
{
	int num;
	cin >> num;
	vector<int> post_order(num);
	vector<int> in_order(num);
	vector<vector<int>> level_order(10000);
	for (int i = 0; i < num; i++)
		cin >> post_order[i];
	for (int i = 0; i < num; i++)
		cin >> in_order[i];


	traversal(post_order, in_order, level_order);
	queue<int> q;
	q.push(*post_order.rbegin());
	cout << q.front();
	while (q.size() != 0)
	{
		for (const auto& a : level_order[q.front()])
			q.push(a);
		q.pop();
		if (q.size() != 0)
			cout << ' ' << q.front();
	}
	return 0;
}