# include <stdio.h>
int main()
{
	int a=0;
	scanf("%d",&a);
	if(a<2400){
		if(a-800<0){
			printf("%d",a+2400-800);
		}
		else{
			printf("%d",a-800);
		}
			
	}
	
	
	return 0;
}
