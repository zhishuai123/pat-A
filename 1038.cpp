#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int num, i;
	cin >> num;
	vector<string> input(num);
	for (int i = 0; i < num; i++)
		cin >> input[i];
	sort(input.begin(), input.end(), [](string &a, string &b)->bool {return stoll(a + b) < stoll(b + a); });
	for (i = 0; i < input.size() && stoi(input[i]) == 0; i++)
		input[i] = "";
	if (i == num)
		input[i - 1] = "0";
	else
		input[i] = to_string(stoi(input[0]));
	for (auto& a : input)
		cout << a;
	return 0;
}