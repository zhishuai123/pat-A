#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<int, float> polynomials;
	int num;
	float f;
	for (int j = 0; j < 2; j++)
	{
		scanf("%d", &num);
		for (int i = num; i > 0; i--)
		{
			scanf("%d%f", &num, &f);
			polynomials[num] += f;
		}
	}
	for (auto i = polynomials.begin(); i != polynomials.end(); i++)
		if ((*i).second == 0)
			polynomials.erase(i);
	printf("%d", polynomials.size());
	for (auto i = polynomials.rbegin(); i != polynomials.rend(); i++)
		printf(" %d %.1f", (*i).first, (*i).second);
	return 0;
}