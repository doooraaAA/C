#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		int c=0;
		
		scanf("%d",&a);
		int e=a;
		for(int b=0;b<a;b++){
			for(int d=0;d<c;d++){
				printf(" ");
			}
			for(int d=0;d<2*e-1;d++){
				printf("*");
			}
			for(int d=0;d<c;d++){
				printf(" ");
			}
			c++;
			e--;
			printf("\n");
		}
	}
	return 0;
} 
