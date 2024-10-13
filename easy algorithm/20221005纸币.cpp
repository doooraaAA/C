#include<stdio.h>
int main()
{
	double a;
	int n;
	int i=0;
	scanf("%d",&n);
	
	int hundred,ten,one,decimal,decile;
	int b,c,d,e;
	for(i=0;i<n;i++){
		scanf("%lf",&a);
		int x=a*100;
		hundred=x/10000;
		x=x%10000;
		b=x/5000;
		x=x%5000;
		ten=x/1000;
		x=x%1000;
		c=x/500;
		x=x%500;
		d=x/200;
		x=x%200;
		one=x/100;
		x=x%100;
		decimal=x/10;
		x=x%10;
		e=x/5;
		x=x%5;
		decile=x;
		printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",hundred,b,ten,c,d,one,decimal,e,decile);
	}
	 
	return 0;
}
