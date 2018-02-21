#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	bool flag = a + b < 0;
	string sum = to_string(abs(a + b));
	if (flag == true)
		cout << '-';
	int tem = sum.size() % 3;
	cout << sum[0];
	for (int i = 1; i < sum.size(); i++)
	{
		if ((i - tem) % 3 == 0)
			cout << ',';
		cout << sum[i];
	}
	return 0;
}