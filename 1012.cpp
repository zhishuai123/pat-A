#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}
int main()
{
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;

	vector<pair<int, int>> A(num1);
	vector<pair<int, int>> C(num1);
	vector<pair<int, int>> M(num1);
	vector<pair<int, int>> E(num1);
	vector<int> input(num2);
	for (int i = 0; i < num1; i++)
	{
		cin >> A[i].first;
		C[i].first = A[i].first;
		M[i].first = A[i].first;
		E[i].first = A[i].first;
		cin >> C[i].second;
		cin >> M[i].second;
		cin >> E[i].second;
		A[i].second = (C[i].second + M[i].second + E[i].second);
	}
	for (int i = 0; i < num2; i++)
		cin >> input[i];
	sort(C.begin(), C.end(), cmp);
	sort(M.begin(), M.end(), cmp);
	sort(E.begin(), E.end(), cmp);
	sort(A.begin(), A.end(), cmp);
	bool flag = false;
	int tem[4] = { 0 };
	for (int i = 0; i < num2; i++)
	{
		for (int ii = 0; ii < 4; ii++)
			tem[ii] = -1;
		for (int j = 0; j < num1; j++)
		{
			if (A[j].first == input[i])
			{
				int x = j;
				while (--x >= 0 && A[x].second == A[j].second);
				tem[0] = x + 1;
			}
			if (C[j].first == input[i])
			{
				int x = j;
				while (--x >= 0 && C[x].second == C[j].second);
				tem[1] = x + 1;
			}
			if (M[j].first == input[i])
			{
				int x = j;
				while (--x >= 0 && M[x].second == M[j].second);
				tem[2] = x + 1;
			}
			if (E[j].first == input[i])
			{
				int x = j;
				while (--x >= 0 && E[x].second == E[j].second);
				tem[3] = x + 1;
			}
		}
		int min_index = -1, min = 10000;
		for (int ii = 0; ii<4; ii++)
		{

			if (tem[ii] != -1)
				if (min > tem[ii])
				{
					min = tem[ii];
					min_index = ii;
				}
		}
		if (min_index == 0)
			cout << tem[min_index] + 1 << " A" << endl;
		else if (min_index == 1)
			cout << tem[min_index] + 1 << " C" << endl;
		else if (min_index == 2)
			cout << tem[min_index] + 1 << " M" << endl;
		else if (min_index == 3)
			cout << tem[min_index] + 1 << " E" << endl;
		else if (min_index == -1)
			cout << "N/A" << endl;
	}
	return 0;
}