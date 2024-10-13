#include<stdio.h>
#include<math.h>
int main()
{
	int a=0,b=0,n=1;
	scanf("%d",&a);
	if(a>=0||a<=1000000){
		if(a%10%2==n%2)
		{b+=1;}
		else {
			b=0;
		}
	while(a>0)
	{	n++;
	a=a/10;
	if(n%2==a%10%2&&a>0)
	{
		b=pow(2,n-1)+b;
	}
	}
	printf("%d\n",b);
	}
	return 0;
}

