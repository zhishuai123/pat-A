
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int num = 0;
	scanf("%d", &num);
	vector<set<int>> input_set(num);
	for (int i = 0; i < input_set.size(); i++)
	{
		scanf("%d", &num);
		for (int j = num; j > 0; j--)
		{
			scanf("%d", &num);
			input_set[i].insert(num);
		}
	}
	scanf("%d", &num);
	int num1, num2, tem;
	float target;
	for (int i = 0; i < num; i++)
	{
		scanf("%d%d", &num1, &num2);
		tem = 0;
		for (auto x = input_set[num1 - 1].begin(), y = input_set[num2 - 1].begin(); x != input_set[num1 - 1].end() && y != input_set[num2 - 1].end();)
		{
			if (*x < *y)
				x++;
			else if (*x > *y)
				y++;
			else
				tem++, x++, y++;
		}

		target = (float)tem / (input_set[num1 - 1].size() + input_set[num2 - 1].size() - tem) * 100;
		printf("%.1f%%\n", target);
	}
	return 0;
}