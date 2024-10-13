#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Hanio_twice(int num)
{
	if(1 == num)
		return 1;
	else
		return 2 * Hanio_twice(num - 1) + 1;
}
int main()
{
	int num = 0;  
	scanf("%d", &num);//塔数
	int ret = Hanio_twice(num);
	printf("完成%d层的汉诺塔需要%d步\n", num, ret);
	return 0;
}

