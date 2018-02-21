#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int num, index1 = 0, index2 = 0, sum = 0, j = 0, k = 0;
	cin >> num;
	vector<int> input(num);
	for (int i = 0; i < num; i++)
		cin >> input[i];
	int max = input[0];
	for (int i = 0; i < num; i++)
	{
		k = i + 1;
		sum += input[i];
		if (sum > max)
		{
			max = sum;
			index1 = j;
			index2 = k;
		}
		if (sum <= 0)
			j = i + 1, sum = 0;
	}
	if (num == 1)
		cout << input[0] << ' ' << input[0] << ' ' << input[0];
	else if (max < 0)
		cout << 0 << ' ' << input[0] << ' ' << input[num - 1];
	else
		cout << max << ' ' << input[index1] << ' ' << input[index2 - 1];
	return 0;
}