#include<stdio.h>
int main()
{
	int a=1,even=0;
	int odd=0;
	if(a<100000||a>0)
	{
		while(a>0)
		{
		scanf("%d",&a);
		if (a%2==0)
		{
		even++;	//ż��������һ 
		}
		else{
			odd++;//����������һ 
		}
	
		}
	printf("%d %d",(odd-1),even);
		
	}	
	return 0;
}
