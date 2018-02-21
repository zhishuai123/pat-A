#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	const char ch[3] = { 'W','T','L' };
	float product = 1, num = 0, max = 0;
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		max = 0;
		for (int j = 0; j < 3; j++)
		{
			scanf("%f", &num);
			if (num > max)
			{
				index = j;
				max = num;
			}
		}
		printf("%c ", ch[index]);
		product *= max;
	}
	printf("%.2f", (product*0.65 - 1) * 2);
	return 0;
}