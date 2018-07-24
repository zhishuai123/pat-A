#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct {
	string id;
	int location;
	int final_rank;
	int local_rank;
	int score;
}info;
bool cmp(info& a, info& b)
{
	if (a.score == b.score)
		return a.id < b.id;
	return a.score > b.score;
}
int main()
{
	int num, num1;
	info tem;
	cin >> num;
	vector<vector<info>> input(num);
	for (int i = 0; i < num; i++)
	{
		cin >> num1;
		for (int j = 0; j < num1; j++)
		{
			cin >> tem.id >> tem.score;
			tem.location = i + 1;
			input[i].push_back(tem);
		}
	}
	for (auto& a : input)
		sort(a.begin(), a.end(), cmp);
	for (auto& a : input)
	{
		a[0].local_rank = 1;
		for (int i = 1; i < a.size(); i++)
			a[i].local_rank = a[i].score == a[i - 1].score ? a[i - 1].local_rank : i + 1;
	}
	vector<info> target;
	for (auto& a : input)
		target.insert(target.end(), a.begin(), a.end());
	sort(target.begin(), target.end(), cmp);
	target[0].final_rank = 1;
	for (int i = 1; i < target.size(); i++)
		target[i].final_rank = target[i].score == target[i - 1].score ? target[i - 1].final_rank : i + 1;
	cout << target.size();
	for (const auto& a : target)
	{
		cout << endl;
		cout << a.id << ' ' << a.final_rank << ' ' << a.location << ' ' << a.local_rank;
	}
	return 0;
}