#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
typedef struct Time {
	int dd;
	int hh;
	int mm;
	friend istream& operator>>(istream& in, Time& t)
	{
		char ch;
		in >> t.dd >> ch >> t.hh >> ch >> t.mm;
		return in;
	}
	friend ostream& operator<<(ostream& out, Time& t)
	{
		out << setw(2) << setfill('0') << t.dd << ':';
		out << setw(2) << setfill('0') << t.hh << ':';
		out << setw(2) << setfill('0') << t.mm;
		return out;
	}
	bool operator<(const Time& tem)
	{
		if (tem.dd == dd)
		{
			if (tem.hh == hh)
				return mm < tem.mm;
			return hh < tem.hh;
		}
		return dd < tem.dd;
	}
	int operator-(const Time& tem)
	{
		int min = 0;
		min += (dd - tem.dd) * 24 * 60;
		min += (hh - tem.hh) * 60;
		min += mm - tem.mm;
		return min;
	}
}Time;
typedef struct record {
	string name;
	Time t;
	bool isOnLine;
}record;
bool cmp(record a, record b)
{
	return a.t < b.t;
}
bool name_cmp(vector<record>a, vector<record>b)
{
	return a[0].name < b[0].name;
}
int rate[24];
int count_cost(Time a, Time b)
{
	int num = b - a;
	if (a.dd == b.dd&&a.hh == b.hh)
		return num*rate[a.hh];
	Time tt = a;
	tt.hh += 1;
	tt.mm = 0;
	int tem = tt - a, count = a.hh + 1, target = (tt - a)*rate[a.hh];
	for (int i = tem; i < num; i += 60)
	{
		if (count > 23)
			count = 0;
		if (num - i < 60)
		{
			target += (num - i)*rate[count];
			i = num;
		}
		else
			target += 60 * rate[count];
		count++;
	}
	return target;
}
int main()
{
	for (int i = 0; i < 24; i++)
		cin >> rate[i];
	int num;
	cin >> num;
	int mouth;
	char ch;
	string str, name;
	Time t;
	vector<vector<record>> records;
	for (int i = 0; i < num; i++)
	{
		bool flag = false;
		cin >> name >> mouth >> ch >> t >> str;
		bool b = str == "on-line" ? true : false;
		for (int j = 0; j < records.size(); j++)
			if (name == records[j][0].name)
			{
				flag = true;
				records[j].push_back({ name,t,b });
				break;
			}
		if (flag == false)
			records.push_back(vector<record>(1, { name,t,b }));
	}
	for (auto& a : records)
		sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < records.size(); i++)
	{
		stack<record> tem;
		vector<record> tem1;
		for (auto a : records[i])
		{
			if (a.isOnLine == true)
				tem.push(a);
			else if (!tem.empty())
			{
				tem1.push_back(tem.top());
				tem1.push_back(a);
				while (!tem.empty())
					tem.pop();
			}
		}
		records[i] = tem1;
	}
	for (auto i = records.begin(); i != records.end();)
		if (i->size() == 0)
			records.erase(i);
		else
			i++;
	sort(records.begin(), records.end(), name_cmp);
	vector<vector<int>> cost(records.size());
	for (int i = 0; i < records.size(); i++)
	{
		for (int j = 0; j < records[i].size(); j += 2)
			cost[i].push_back(count_cost(records[i][j].t, records[i][j + 1].t));
	}
	for (int i = 0; i < records.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < cost[i].size(); j++)
			sum += cost[i][j];
		cout << records[i][0].name << ' ' << setw(2) << setfill('0') << mouth << endl;
		for (int j = 0; j < records[i].size(); j += 2)
		{
			cout << records[i][j].t << ' ' << records[i][j + 1].t << ' ' << records[i][j + 1].t - records[i][j].t;
			printf(" $%.2f\n", float(cost[i][j / 2]) / 100);
		}
		printf("Total amount: $%.2f\n", float(sum) / 100);
	}

	return 0;
}

