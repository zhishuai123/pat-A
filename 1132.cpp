#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int input;
	for (int i = 0; i < num; i++)
	{
		cin >> input;
		string str = to_string(input);
		if ((stoi(string(str.begin(), str.begin() + str.size() / 2))*stoi(string(str.begin() + str.size() / 2, str.end()))) == 0)
			cout << "No" << endl;
		else if (input % (stoi(string(str.begin(), str.begin() + str.size() / 2))*stoi(string(str.begin() + str.size() / 2, str.end()))) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}