#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m,n;
		int h=0;
		scanf("%d %d",&m,&n);
		if(100<=m&&m<n&&n<=999){
			for(int a=m;a<=n;a++){
				int x;
				x=a;
				int b=x/100;
				int c=x%100/10;
				int d=x%10;
				int e=b*b*b+c*c*c+d*d*d;
				if(a==e){
					printf("%d ",a);
					h=1;
				}
			}
			if(h==0){
				printf("-1");
			}
		}
		printf("\n");
	}
	return 0;
}
