#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num = 1000000000;
	int tem1[10] = { 0,1,20,300,4000,50000,600000,7000000,80000000,900000000 };
	int tem2[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
	cin >> num;
	string str = to_string(num);
	int target = *str.rbegin() != '0' ? 1 : 0;
	for (int i = 1; i <= str.size() - 1; i++)
		if (str[str.size() - i - 1] - '0' == 1)
			target += tem1[i] + stoi(string(str.end() - i, str.end())) + 1;
		else if (str[str.size() - i - 1] - '0' > 1)
			target += (str[str.size() - i - 1] - '0')*tem1[i] + tem2[i];
	cout << target;
	return 0;
}