
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
pair<int, int> level(vector<vector<int>>& tree, int root, int num)
{
	if (tree[root].size() == 0)
		return { num,1 };

	int max = -1, sum = 0;
	pair<int, int> tem;
	for (int i = 0; i < tree[root].size(); i++)
	{
		tem = level(tree, tree[root][i], num + 1);
		if (max < tem.first)
		{
			max = tem.first;
			sum = tem.second;
		}
		else if (max == tem.first)
			sum += tem.second;
	}
	return { max,sum };
}
int main()
{
	int num;
	double price, r;
	cin >> num >> price >> r;
	vector<int> input(num);
	for (int i = 0; i < num; i++)
		cin >> input[i];
	vector<vector<int>> sell(num);
	int root;
	for (int i = 0; i < num; i++)
	{
		if (input[i] != -1)
			sell[input[i]].push_back(i);
		else
			root = i;
	}
	pair<int, int> tem = level(sell, root, 0);
	for (int i = 0; i < tem.first; i++)
		price *= (1 + r / 100);
	printf("%.2f %d", price, tem.second);
	return 0;
}