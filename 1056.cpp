
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	vector<int> mouse(num1);
	vector<int> order(num1);
	for (int i = 0; i < num1; i++)
		cin >> mouse[i];
	for (int i = 0; i < num1; i++)
		cin >> order[i];
	vector<int> rank(num1, 1);
	int max = 0;
	int tem1 = num1, pre_index = -1;
	while (tem1 != 1)
	{
		tem1 = tem1%num2 == 0 ? tem1 / num2 : tem1 / num2 + 1;
		pre_index = -1;
		max = -1;
		for (int i = 0, j = 1; i < num1; i++)
		{
			if (rank[order[i]] == 1)
			{
				if (max < mouse[order[i]])
				{
					if (pre_index != -1)
						rank[order[pre_index]] = tem1 + 1;
					max = mouse[order[i]];
					pre_index = i;
				}
				else
					rank[order[i]] = tem1 + 1;
				if (j%num2 == 0)
					max = -1, pre_index = -1;
				j++;
			}
		}
	}
	cout << rank[0];
	for (int i = 1; i < num1; i++)
		cout << ' ' << rank[i];
	return 0;
}