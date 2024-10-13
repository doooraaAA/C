#include<stdio.h>
int main()
{
	int count=0,sum=0;
	int m,n;
	int i=2,j;
	scanf("%d %d",&n,&m);
	do 
	{
		for(j=2;j<=i;j++)
		{
			if(i%j==0) break;
		}
		if(i==j)
		{
			count++;
			if(count>=n&&count<=m)
			{sum+=i;
			}
		}
		i++;
	}while(count<=m);
	printf("%d",sum);
	return 0;
}
