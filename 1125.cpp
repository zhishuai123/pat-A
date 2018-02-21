#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	vector<int> input(num);
	for (int i = 0; i < num; i++)
		scanf("%d", &input[i]);
	sort(input.begin(), input.end());
	double target = input[0];
	for (int i = 1; i < num; i++)
		target = (target + input[i]) / 2;
	printf("%d", (int)target);
	return 0;
}