
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	vector<pair<int, int>> input(num1);
	vector<int> windows(num2);
	int hh, mm, ss;
	char ch;
	for (int i = 0; i < num1; i++)
	{
		cin >> hh >> ch >> mm >> ch >> ss >> input[i].second;
		input[i].first = (hh - 8) * 3600 + mm * 60 + ss;
		input[i].second *= 60;
	}

	for (auto i = input.begin(); i != input.end();)
	{
		if (i->first > 540 * 60)
			i = input.erase(i);
		else
			i++;
	}
	sort(input.begin(), input.end(), cmp);
	int now = 0, min_time, min_index;
	long long sum = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (now < input[i].first)
		{
			for (int j = 0; j < windows.size(); j++)
				windows[j] -= input[i].first - now;
			now = input[i].first;
		}
		for (int j = 0; j < windows.size(); j++)
			if (windows[j] < 0)
				windows[j] = 0;
		min_time = 100000, min_index = -1;
		for (int j = 0; j < windows.size(); j++)
		{
			if (min_time > windows[j])
			{
				min_time = windows[j];
				min_index = j;
			}
		}
		for (int j = 0; j < windows.size(); j++)
			windows[j] -= min_time;
		windows[min_index] = input[i].second;
		now += min_time;
		sum += now - input[i].first;
	}
	printf("%.1f", float(sum) / input.size() / 60);
	return 0;
}