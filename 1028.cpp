#include<iostream>
#include<string>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct {
	int id;
	string name;
	int grade;
}info;
bool cmp1(const info& a, const info& b)
{
	return a.id < b.id;
}
bool cmp2(const info& a, const info& b)
{
	if (a.name == b.name)
		return a.id < b.id;
	return a.name < b.name;
}
bool cmp3(const info& a, const info& b)
{
	if (a.grade == b.grade)
		return a.id < b.id;
	return a.grade < b.grade;
}
bool(*choice(int num))(const info&, const info&)
{
	if (num == 1)
		return cmp1;
	else if (num == 2)
		return cmp2;
	else if (num == 3)
		return cmp3;
	return NULL;
}

int main()
{
	ios::sync_with_stdio(false);
	int num, num1;
	cin >> num >> num1;
	vector<info> input(num);
	for (int i = 0; i < num; i++)
		cin >> input[i].id >> input[i].name >> input[i].grade;
	sort(input.begin(), input.end(), choice(num1));
	for (const auto& a : input)
		cout << setw(6) << setfill('0') << a.id << ' ' << a.name << ' ' << a.grade << '\n';
	return 0;
}