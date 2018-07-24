#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
	int num;
	cin >> num;
	map<int, int> m;
	set<int> s;
	vector<int> input(num);
	for (int i = 0; i < num; i++)
	{
		cin >> input[i];
		if (m[input[i]]++ == 0)
			s.insert(i);
	}
	for (auto& a : s)
		if (m[input[a]] == 1)
		{
			cout << input[a];
			return 0;
		}
	cout << "None";
	return 0;
}