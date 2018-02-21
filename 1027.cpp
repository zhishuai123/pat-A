#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	cout << '#' << setiosflags(ios::uppercase) << hex << num1 / 13 << num1 % 13 << num2 / 13 << num2 % 13 << num3 / 13 << num3 % 13;
	return 0;
}