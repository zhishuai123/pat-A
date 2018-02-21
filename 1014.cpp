
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int Time = 0;
int min_time, min_index;
typedef class window {
	queue<pair<int, int>> que;
public:
	bool empty()
	{
		return que.empty();
	}
	int get_time()
	{
		if (!empty())
			return que.front().second;
		else
			return -1;
	}
	void deal()
	{
		que.pop();
	}
	void over_time(int num)
	{
		que.front().second -= num;
	}
	void push(pair<int, int> people)
	{
		que.push(people);
	}
	int get_size()
	{
		return que.size();
	}
	int get_people()
	{
		return que.front().first;
	}
	void clear()
	{
		while (!que.empty())
			que.pop();
	}
}window;
typedef class bank {
	queue<pair<int, int>> outOfLine;
	vector<window> windows;
	vector<int> record;
	int max_size;
public:
	bank(int num, int m, queue<pair<int, int>> out) :max_size(m), windows(num), outOfLine(out), record(outOfLine.size(), -1) {}
	bool outOfLineEmpty()
	{
		return outOfLine.empty();
	}
	void push(int num)
	{
		windows[num].push(outOfLine.front());
		outOfLine.pop();
	}
	bool windowsEmpty()
	{
		bool flag = true;
		for (int i = 0; i < windows.size(); i++)
			flag &= windows[i].empty();
		return flag;
	}
	void deal_one()
	{

		if (Time >= 540)
		{
			for (int i = 0; i < windows.size(); i++)
			{
				if (!windows[i].empty() && i != min_index)
					record[windows[i].get_people()] = Time + windows[i].get_time();
			}
			for (int i = 0; i < windows.size(); i++)
				windows[i].clear();
			while (!outOfLine.empty())
				outOfLine.pop();
			return;
		}
		min_time = 100000, min_index = -1;
		for (int i = 0; i < windows.size(); i++)
		{
			if (!windows[i].empty() && windows[i].get_time() < min_time)
			{
				min_time = windows[i].get_time();
				min_index = i;
			}
		}
		for (int i = 0; i < windows.size(); i++)
		{
			if (!windows[i].empty())
				windows[i].over_time(min_time);

		}
		Time += min_time;
		record[windows[min_index].get_people()] = Time;
		windows[min_index].deal();

		if (!outOfLine.empty())
			push(min_index);
	}
	void first_push()
	{
		for (int i = 0; i < max_size; i++)
			for (int j = 0; j < windows.size(); j++)
				if (!outOfLine.empty())
				{
					windows[j].push(outOfLine.front());
					outOfLine.pop();
				}
	}
	vector<int>& get_target()
	{
		return record;
	}
}bank;
int main()
{
	int num_win, max_size, num1, num_target;
	cin >> num_win >> max_size >> num1 >> num_target;
	vector<int> input(num1);
	for (int i = 0; i < num1; i++)
		cin >> input[i];
	queue<pair<int, int>> outOfLine;
	for (int i = 0; i < num1; i++)
		outOfLine.push({ i,input[i] });
	bank B(num_win, max_size, outOfLine);
	B.first_push();

	while (!B.windowsEmpty())
		B.deal_one();
	auto target = B.get_target();
	int tem, hh, mm;
	for (int i = 0; i < num_target; i++)
	{
		cin >> tem;
		tem--;
		if (target[tem] == -1)
			cout << "Sorry" << endl;
		else
		{
			hh = 8 + target[tem] / 60;
			mm = target[tem] % 60;
			printf("%02d:%02d\n", hh, mm);
		}
	}

	return 0;
}