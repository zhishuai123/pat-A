#include<iostream>
#include<string>
#include<vector>
using namespace std;
string reverse(string a)
{
	for (int i = 0, j = a.size() - 1; i < j; i++, j--)
		swap(a[i], a[j]);
	return a;
}
string Plus(string a, string b)
{
	for (int i = a.size() - 1; i > 0; i--)
	{
		a[i] += b[i] - '0';
		if (a[i] > '9')
		{
			a[i] -= 10;
			a[i - 1] += 1;
		}
	}
	a[0] += b[0] - '0';
	if (a[0] > '9')
	{
		a = "1" + a;
		a[1] -= 10;
	}
	return a;
}
bool isPalindromic(string a)
{
	return a == reverse(a);
}
int main()
{
	string num;
	int step, count = 0;
	cin >> num >> step;
	while (count < step)
	{
		if (isPalindromic(num))
			break;
		num = Plus(num, reverse(num));
		count++;
	}
	cout << num << endl;
	cout << count;
	return 0;
}