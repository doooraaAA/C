#include <stdio.h>
struct DNA
{
	char order[50];
	int num;
} ;
int sum(char D[],int len);
int main()
{
	struct DNA a[101],temp;
	int n,m;
	int i,j;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%s",a[i].order);
			a[i].num=sum(a[i].order,n);
		}
		for(i=0;i<m-1;i++)
		{
			for(j=i;j>=0;j--)
			{
				if(a[j].num>a[j+1].num)
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		} 
		for(i=0;i<m;i++)
		{
			puts(a[i].order);
		}
		printf("********************\n");	
	return 0;
}
int sum(char D[],int len)
{
	int i,j;
	int all=0;
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(D[i]>D[j])
				all++;
		}
	} 
	return all;
}

