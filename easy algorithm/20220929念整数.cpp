#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,i;
	scanf("%d",&a);
	if (-100000<a&&a<100000)
	{	i=a;
		if(a<=0)
		{i=-a;
		a=-a;
		printf("fu ");
		}
		while(i>10)
		{
			n=0;
			do
			{
				a=a/10;
				n++;
			}while(a>10);
			switch(a)
			{	case 0:printf("ling ");break;
				case 1:printf("yi ");break;
				case 2:printf("er ");break;
				case 3:printf("san ");break;
				case 4:printf("si ");break;
				case 5:printf("wu  ");break;
				case 6:printf("liu ");break;
				case 7:printf("qi ");break;
				case 8:printf("ba ");break;
				case 9:printf("jiu ");break;
				}
				a=i-a*pow(10,n);
				i=a;
			}
			switch(a)
			{	case 0:printf("ling");break;
				case 1:printf("yi");break;
				case 2:printf("er");break;
				case 3:printf("san");break;
				case 4:printf("si");break;
				case 5:printf("wu");break;
				case 6:printf("liu");break;
				case 7:printf("qi");break;
				case 8:printf("ba");break;
				case 9:printf("jiu");break;
				}
		
		
		}
	

	return 0;
}
