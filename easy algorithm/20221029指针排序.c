#include<stdio.h>
int sort(int num[],int n);
int main(){
	int n;
	scanf("%d",&n);
	int num[n];
	for(int i=0;i<n;i++){
	scanf("%d",&num[i]);	//TODO
	}
	sort(num,n);
	for(int i=0;i<n-1;i++){
		printf("%d ",num[i]);
	}
	printf("%d\n",num[n-1]);
	return 0;
}
int sort(int num[],int n){
	int t;
	for(int x=0;x<n;++x){
		for(int i=x;i<n;i++){
			if(num[x]>num[i]){
				t=num[x];
				num[x]=num[i];
				num[i]=t;
			}
		}
	}
	return 0;
}
