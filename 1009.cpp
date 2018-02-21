#include<stdio.h>
#include<map>
using namespace std;
int main()
{
	map<int, float> polynomials;
	int num, tem1;
	scanf("%d", &num);
	float tem2;
	for (int i = 0; i < num; i++)
	{
		scanf("%d%f", &tem1, &tem2);
		polynomials[tem1] = tem2;
	}
	map<int, float> target;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d%f", &tem1, &tem2);
		for (const auto&a : polynomials)
			target[tem1 + a.first] += tem2*a.second;
	}
	for (auto i = target.begin(); i != target.end(); i++)
		if ((*i).second == 0)
			target.erase(i);
	printf("%d", target.size());
	for (auto i = target.rbegin(); i != target.rend(); i++)
		printf(" %d %.1f", (*i).first, (*i).second);
	return 0;
}