#include<stdio.h>
int isComposite(int);
int main(){
	int n;
	scanf("%d",&n);
	if(2<=n&&n<=1000){
	printf("%d",isComposite(n));
	}
	return 0;
}
int isComposite(int n){
	int ret=0;
	for(int i=2;i<n;i++){
		if(n%i==0){
		ret =1;	//TODO
		}
	}
	return ret;
}
