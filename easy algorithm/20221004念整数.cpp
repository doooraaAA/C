#include<stdio.h>
int main()
{
	int num,sum=0,a=0,count=0;
	scanf("%d",&num);
	if(num<0)
	{printf("fu ");
	num=-num;
	}
	if(num!=0)
	{while(num>0){
		sum=sum*10+num%10;
		num/=10;
		count++;
	}
	do{
		a=sum%10;
		switch(a){
					case 0:printf("ling");break;
				case 1:printf("yi");break;
				case 2:printf("er");break;
				case 3:printf("san");break;
				case 4:printf("si");break;
				case 5:printf("wu");break;
				case 6:printf("liu");break;
				case 7:printf("qi");break;
				case 8:printf("ba");break;
				default:printf("jiu");
	}
	count--;
	if(count>0){
		printf(" ");
	}
	sum/=10;
	}while(count>0);
	}
	else{
		printf("ling");
	}
	return 0;
}
