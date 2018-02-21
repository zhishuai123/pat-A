#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef struct book {
	string id;
	string name;
	string author;
	set<string> keyword;
	string publisher;
	string time;
	friend istream& operator>>(istream& in, book& b)
	{
		string tem;
		char ch = 0;
		getline(in, b.id);
		getline(in, b.name);
		getline(in, b.author);
		while (ch != '\n')
		{
			in >> tem;
			b.keyword.insert(tem);
			in.get(ch);
		}
		getline(in, b.publisher);
		in >> b.time;
		in.get();
		return in;
	}
}book;
bool compare(book&a, book& b)
{
	return a.id < b.id;
}
int main()
{
	int num;
	bool flag = false;
	cin >> num;
	vector<book> input(num);
	cin.get();
	for (int i = 0; i < num; i++)
		cin >> input[i];
	cin >> num;
	string tem;
	cin.get();
	sort(input.begin(), input.end(), compare);
	for (int i = 0; i < num - 1; i++)
	{
		flag = false;

		getline(cin, tem);
		if (tem[0] == '1')
		{
			cout << tem << endl;
			for (const auto& a : input)
				if (a.name == tem.substr(3, tem.size()))
				{
					cout << a.id << endl;
					flag = true;
				}
		}
		else if (tem[0] == '2')
		{
			cout << tem << endl;
			for (const auto& a : input)
				if (a.author == tem.substr(3, tem.size()))
				{
					cout << a.id << endl;
					flag = true;
				}
		}
		else if (tem[0] == '3')
		{
			cout << tem << endl;
			for (const auto& a : input)
				if (a.keyword.find(tem.substr(3, tem.size())) != a.keyword.end())
				{
					cout << a.id << endl;
					flag = true;
				}
		}
		else if (tem[0] == '4')
		{
			cout << tem << endl;
			for (const auto& a : input)
				if (a.publisher == tem.substr(3, tem.size()))
				{
					cout << a.id << endl;
					flag = true;
				}
		}
		else if (tem[0] == '5')
		{
			cout << tem << endl;
			for (const auto& a : input)
				if (a.time == tem.substr(3, tem.size()))
				{
					cout << a.id << endl;
					flag = true;
				}
		}
		if (flag == false)
			cout << "Not Found" << endl;
	}

	flag = false;
	getline(cin, tem);
	if (tem[0] == '1')
	{
		cout << tem;
		for (const auto& a : input)
			if (a.name == tem.substr(3, tem.size()))
			{
				cout << endl;
				cout << a.id;
				flag = true;
			}
	}
	else if (tem[0] == '2')
	{
		cout << tem;
		for (const auto& a : input)
			if (a.author == tem.substr(3, tem.size()))
			{
				cout << endl;
				cout << a.id;
				flag = true;
			}
	}
	else if (tem[0] == '3')
	{
		cout << tem;
		for (const auto& a : input)
			if (a.keyword.find(tem.substr(3, tem.size())) != a.keyword.end())
			{
				cout << endl;
				cout << a.id;
				flag = true;
			}
	}
	else if (tem[0] == '4')
	{
		cout << tem;
		for (const auto& a : input)
			if (a.publisher == tem.substr(3, tem.size()))
			{
				cout << endl;
				cout << a.id;
				flag = true;
			}
	}
	else if (tem[0] == '5')
	{
		cout << tem;
		for (const auto& a : input)
			if (a.time == tem.substr(3, tem.size()))
			{
				cout << endl;
				cout << a.id;
				flag = true;
			}
	}
	if (flag == false)
	{
		cout << endl;
		cout << "Not Found";
	}
	return 0;
}