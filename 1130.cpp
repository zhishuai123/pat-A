
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct {
	string val;
	int left;
	int right;
}node;
bool in_order(vector<node>& tree, int root, string& target)
{
	if (root == -1)
		return true;
	if (tree[root].left == -1 && tree[root].right == -1)
	{
		target += tree[root].val;
		return true;
	}
	string tem1, tem2, target1, target2;
	if (in_order(tree, tree[root].left, tem1) == true)
		target1 = tem1;
	else
		target1 = "(" + tem1 + ")";
	if (in_order(tree, tree[root].right, tem2) == true)
		target2 = tem2;
	else
		target2 = "(" + tem2 + ")";
	target = target1 + tree[root].val + target2;
	return false;
}
int main()
{
	int num;
	cin >> num;
	vector<node> input(num + 1);
	for (int i = 1; i <= num; i++)
		cin >> input[i].val >> input[i].left >> input[i].right;
	vector<bool> isRoot(num + 1, true);
	for (int i = 1; i <= num; i++)
	{
		if (input[i].left != -1)
			isRoot[input[i].left] = false;
		if (input[i].right != -1)
			isRoot[input[i].right] = false;
	}
	int root;
	for (int i = 1; i <= num; i++)
		if (isRoot[i] == true)
			root = i;
	string target;
	in_order(input, root, target);
	cout << target;
	return 0;
}