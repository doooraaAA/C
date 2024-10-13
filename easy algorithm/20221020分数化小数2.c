#include<stdio.h>
int main()
{
	int n;
	int a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d",&a,&b,&c);
		printf("%d.",a/b);
		for(int i=0;i<c-1;i++)
		{
			a=(a%b)*10;
			printf("%d",a/b);
		}
		if(a/b>=5)
		{
			printf("%d\n",a/b+1);
		}
		else
		{
			printf("%d\n",a/b);
		}
	}
	return 0;
}
