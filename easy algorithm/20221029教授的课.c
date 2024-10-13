#include<stdio.h>
int IsCancel(int a[], int n, int k);
int main(){
	int N,K;	
	scanf("%d %d",&N,&K);
	int a[N];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	if(IsCancel(a,N,K)==0){
		printf("NO");
	}
	else{
		printf("YES");
	}
	return 0;
}
int IsCancel(int a[], int n, int k){
	int ret;
	for(int i=0;i<n;i++){
		if(a[i]<=0){
			k--;
		}
	}
	if(k<=0){
		ret=0;
	}
	else{
		ret=1;
	}
	return ret;
}
