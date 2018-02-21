
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int num = 0;
	bool flag = false;
	cin >> num;
	vector<pair<string, string>> a_p(num);
	vector<int> index;
	for (int i = 0; i < num; i++)
		cin >> a_p[i].first >> a_p[i].second;
	for (int i = 0; i < num; i++)
	{
		flag = false;
		for (auto &c : a_p[i].second)
			switch (c)
			{
			case '1':
				c = '@';
				flag = true;
				break;
			case '0':
				c = '%';
				flag = true;
				break;
			case 'l':
				c = 'L';
				flag = true;
				break;
			case 'O':
				c = 'o';
				flag = true;
				break;
			}
		if (flag == true)
			index.push_back(i);
	}
	if (index.size() == 0 && num != 1)
		cout << "There are " << num << " accounts and no account is modified";
	else if (index.size() == 0 && num == 1)
		cout << "There is 1 account and no account is modified");
	else
	{
		cout << index.size();
		for (const auto& num : index)
		{
			cout << endl;
			cout << a_p[num].first << ' ' << a_p[num].second;
		}
	}
	return 0;
}