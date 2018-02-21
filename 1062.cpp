#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ID first
#define VIRTUE second.first
#define TALENT second.second
bool mycompare(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
	if (a.VIRTUE + a.TALENT == b.VIRTUE + b.TALENT)
	{
		if (a.VIRTUE == b.VIRTUE)
		{
			return a.ID < b.ID;
		}
		return a.VIRTUE > b.VIRTUE;
	}
	return a.VIRTUE + a.TALENT > b.VIRTUE + b.TALENT;
}

int main()
{
	ios::sync_with_stdio(false);
	int num, L, H;
	cin >> num >> L >> H;
	vector<pair<int, pair<int, int>>> input(num);
	for (int i = 0; i < num; i++)
		cin >> input[i].ID >> input[i].VIRTUE >> input[i].TALENT;
	vector<pair<int, pair<int, int>>> sage;
	vector<pair<int, pair<int, int>>> nobleman;
	vector<pair<int, pair<int, int>>> fool_man;
	vector<pair<int, pair<int, int>>> others;
	for (int i = 0; i < num; i++)
	{
		if (input[i].VIRTUE >= L&&input[i].TALENT >= L)
		{
			if (input[i].VIRTUE >= H&&input[i].TALENT >= H)
				sage.push_back(input[i]);
			else if (input[i].VIRTUE >= H)
				nobleman.push_back(input[i]);
			else if (input[i].VIRTUE >= input[i].TALENT)
				fool_man.push_back(input[i]);
			else
				others.push_back(input[i]);
		}
	}
	sort(sage.begin(), sage.end(), mycompare);
	sort(nobleman.begin(), nobleman.end(), mycompare);
	sort(fool_man.begin(), fool_man.end(), mycompare);
	sort(others.begin(), others.end(), mycompare);
	cout << sage.size() + nobleman.size() + fool_man.size() + others.size();
	for (int i = 0; i < sage.size(); i++)
	{
		cout << endl;
		cout << sage[i].ID << ' ' << sage[i].VIRTUE << ' ' << sage[i].TALENT;
	}
	for (int i = 0; i < nobleman.size(); i++)
	{
		cout << endl;
		cout << nobleman[i].ID << ' ' << nobleman[i].VIRTUE << ' ' << nobleman[i].TALENT;
	}
	for (int i = 0; i < fool_man.size(); i++)
	{
		cout << endl;
		cout << fool_man[i].ID << ' ' << fool_man[i].VIRTUE << ' ' << fool_man[i].TALENT;
	}
	for (int i = 0; i < others.size(); i++)
	{
		cout << endl;
		cout << others[i].ID << ' ' << others[i].VIRTUE << ' ' << others[i].TALENT;
	}
	return 0;
}