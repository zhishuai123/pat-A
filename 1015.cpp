
#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int reverse(int num, int radix)
{
	string str;
	while (num > 0)
	{
		str += to_string(num%radix);
		num /= radix;
	}

	int target = 0;
	for (int i = 0; i < str.size(); i++)
	{
		target *= radix;
		target += str[i] - '0';
	}
	return target;
}
int main()
{
	ios::sync_with_stdio(false);
	bool isPrime[100000];
	for (int i = 2; i < 100000; i++)
		isPrime[i] = true;
	for (int i = 2; i < 400; i++)
		if (isPrime[i] == true)
			for (int j = i + 1; j < 100000; j++)
				if (j%i == 0)
					isPrime[j] = false;

	int num1, num2, num3, re;
	cin >> num1;
	while (num1 > 0)
	{
		cin >> num2;
		re = reverse(num1, num2);
		if (isPrime[re] && isPrime[num1])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> num1;
	}
	return 0;
}