#include<stdio.h>
int main(){
	int n;
	int a;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(a>=0&&a%4==0){
			if(a%100==0&&a%400!=0){
				printf("no\n");
			}
			else{
				printf("yes\n");
			}
		}
		else{
			printf("no\n");
		}
	}
	return 0;
}
