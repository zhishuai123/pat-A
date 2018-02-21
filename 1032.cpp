#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	vector<pair<char, int>> list(100001, { -2,-1 });
	int num1, num2, num3, tem1;
	char ch;
	scanf("%d%d%d", &num1, &num2, &num3);
	for (int i = 0; i < num3; i++)
	{
		scanf("%d", &tem1);
		scanf(" %c %d", &list[tem1].first, &list[tem1].second);
	}
	tem1 = num2;
	while (tem1 != -1)
	{
		list[tem1].first = -1;
		tem1 = list[tem1].second;
	}
	tem1 = num1;
	while (tem1 != -1)
	{
		if (list[tem1].first == -1)
		{
			printf("%5d", tem1);
			return 0;
		}
		tem1 = list[tem1].second;
	}
	printf("-1");
	return 0;
}