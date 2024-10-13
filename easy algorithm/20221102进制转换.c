#include<stdio.h>
int main(){
	int n,a,b,x;
	int num[100]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(1<=a&&a<=100000&&2<=b&&b<=10){
			x=0;
			while(a>=1){
			num[x]=a%b;
			a=a/b;
			x++;
			}
		}
		while(x>0){
			printf("%d",num[x-1]);
			x--;
		}
		printf("\n");
	}

	return 0;
}
