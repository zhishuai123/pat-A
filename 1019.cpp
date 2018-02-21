
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> n1, n2;
	int num1, num2;
	cin >> num1 >> num2;
	if (num1 == 0)
	{
		cout << "Yes" << endl;
		cout << "0";
		return 0;
	}

	while (num1 != 0)
	{
		n1.push_back(num1%num2);
		num1 /= num2;
	}
	for (auto i = n1.rbegin(); i != n1.rend(); i++)
		n2.push_back(*i);
	if (n1 == n2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << n2[0];
	for (auto i = n2.begin() + 1; i != n2.end(); i++)
		cout << ' ' << *i;
	return 0;
}