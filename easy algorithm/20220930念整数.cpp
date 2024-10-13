#include<stdio.h>
int main()
{
	int n,i,k=1,copy;
	scanf("%d",&n);
	if(n>-100000&&n<100000)
	{if(n<0){n=-n;
	printf("fu ");
	}
		copy=n;
		while(copy>9){
			k*=10;
			copy/=10;
		}
		for(k>0;k=k/10;){
			i=n/k;
			switch(i){
					case 0:printf("ling ");break;
				case 1:printf("yi ");break;
				case 2:printf("er ");break;
				case 3:printf("san ");break;
				case 4:printf("si ");break;
				case 5:printf("wu  ");break;
				case 6:printf("liu ");break;
				case 7:printf("qi ");break;
				case 8:printf("ba ");break;
				default:printf("jiu ");
			}
			n=n%k;
		}
	}
	printf("examine");
	return 0;
}
