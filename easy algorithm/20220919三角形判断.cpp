#include<stdio.h>
int main()
{
	int a,b,c,n,i;
	double cosA,cosB,cosC;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d,%d,%d",&a,&b,&c);
		if(a+b>c&&b+c>a&&a+c>b)
		{
			cosA=(b*b+c*c-a*a)/2*b*c;
			cosB=(a*a+c*c-b*b)/2*a*c;
			cosC=(a*a+b*b-c*c)/2*a*b;
			if(cosA>0&&cosB>0&&cosC>0)
			{
				printf("acute\n");
			}
			else if(cosA<0||cosB<0||cosC<0)
			{
				printf("obtuse\n"); 
			}
			else if(cosA==0||cosB==0||cosC==0)
			{
				printf("right\n");
			}
			else
			{
				printf("illegal\n");
			}
		}
		else
		{
			printf("illegal\n");
		} 
	}
	return 0;
}
