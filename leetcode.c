#include<stdio.h>

int IsReverse(int num)
{
	if (num == 0)
		return 0;
	int sum = 0;
	for (int i = num; i > 0; i /= 10)
	{
		sum = sum * 10 + i % 10;
	}
	return sum - num;
}

int main()
{
	int i = 0;
	scanf("%d", &i);
	int ret = IsReverse(i);
	if (ret == 0)
	{
		printf("yes");
	}
	else
		printf("no");

	return 0;
}
