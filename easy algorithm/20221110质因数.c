#include<stdio.h>
int prime(int a);
int divide(int a);
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m,a,b;
		scanf("%d",&m);
		if(prime(m)==0){
			printf("%d",m);
		}
		else{
			a=divide(m);
			m=m/a;
			printf("%d",m);
			while(prime(a)){
				b=a;
				a=divide(a);
				printf("*%d",b/a);
			}
			printf("*%d",a);
		}
		printf("\n");
	}
	return 0;
}
int prime(int a){
	int ret=0;
	for(int i=2;i<a;i++){
		if(a%i==0){
			ret=1;
			break;
		}
	}
	return ret;
}
int divide(int a){
	int ret=a;
	for(int i=a-1;i>1;i--){
		if(a%i==0){
			ret=i;
			return ret;
		}
	}
	return ret;
}
