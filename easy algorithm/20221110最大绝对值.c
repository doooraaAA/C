#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
	int m,t;
	scanf("%d",&m);
	int num[m],swi[m];
	for(int i=0;i<m;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<m;i++){
		if(num[i]<=0){
			swi[i]=-num[i];
		}
		else{swi[i]=num[i];}
	}
	for(int i=0;i<m;i++){
		for(int a=i+1;a<m;a++){
			if(swi[i]<swi[a]){
			t=swi[i];
			swi[i]=swi[a];
			swi[a]=t;
			}
		}
	}
	printf("%d %d\n",swi[0],swi[1]);
	}
	return 0;
}
