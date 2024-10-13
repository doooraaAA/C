#include<stdio.h>
int main(){
	 int n;
	 int a,b,c;
	 scanf("%d",&n);
	 for(int i=0;i<n;i++){
		 scanf("%d",&a);
		if(a>999||a<100){
			printf("illegal\n");
		}
		else{
			c=a/100;
			b=a/10;
			printf("%d,%d,%d\n",a%10,b%10,c);
		}
	 }
	 return 0;
}
