#include <stdio.h>
#include <string.h>
int main(void)	
{	int n;
	scanf("%d",&n);
	for(int t=0;t<n;t++){
	int bigInteger_1[501] = {0}; 
	int bigInteger_2[501] = {0}; 
	char sNum_1[501] = {'\0'};  
	char sNum_2[501] = {'\0'}; 
	scanf("%s %s", sNum_1, sNum_2);
	for (int i = 0, j = strlen(sNum_1) - 1; j >= 0; )
	{
		bigInteger_1[i++] = sNum_1[j--] - '0';
	}
	for (int i = 0, j = strlen(sNum_2) - 1; j  >= 0; )
	{
		bigInteger_2[i++] = sNum_2[j--] - '0';
	}
	int k = 0;
	while (k <= 500)
	{	bigInteger_1[k] += bigInteger_2[k];
		if (bigInteger_1[k] >= 10)
		{
			bigInteger_1[k+1]++;
			bigInteger_1[k] -= 10;
			
		} 
		k++;
	}
	int mark = 0; 
	int i = 0;
	for (i = 500; i >= 0; i--)
	{
		if (bigInteger_1[i] != 0)
		{
			mark = i; 
			break; 
		}
	}
	if (i == -1)
	{
		printf("0\n");
	}
	else
	{
		for (int i = mark; i >= 0; i--)
		{
			printf("%d", bigInteger_1[i]); 
		}
		putchar('\n');
	}
	}
	
	return 0;
}

