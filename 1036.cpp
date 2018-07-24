#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef struct {
	string name;
	string id;
	int grade;
}info;
int main()
{
	int num;
	cin >> num;
	vector<info> male;
	vector<info> famale;
	info tem;
	char ch;
	for (int i = 0; i < num; i++)
	{
		cin >> tem.name >> ch >> tem.id >> tem.grade;
		if (ch == 'M')
			male.push_back(tem);
		else
			famale.push_back(tem);
	}
	int max_index = -1, min_index = -1;
	for (int i = 0; i < famale.size(); i++)
		max_index = max_index == -1 || famale[max_index].grade < famale[i].grade ? i : max_index;
	for (int i = 0; i < male.size(); i++)
		min_index = min_index == -1 || male[min_index].grade > male[i].grade ? i : min_index;
	if (max_index != -1)
		cout << famale[max_index].name << ' ' << famale[max_index].id << endl;
	else
		cout << "Absent" << endl;
	if (min_index != -1)
		cout << male[min_index].name << ' ' << male[min_index].id << endl;
	else
		cout << "Absent" << endl;
	if (min_index != -1 && max_index != -1)
		cout << famale[max_index].grade - male[min_index].grade;
	else
		cout << "NA";
	return 0;
}