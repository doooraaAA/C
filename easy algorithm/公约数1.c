#include<stdio.h>
int main(){
	int n;
	int a,b,t,answer;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a>=b){
			t=b;//TODO
		}
		else{
			t=a;
		}
		for(int x=1;x<=t;x++){
			if(a%x==0&&b%x==0){
				answer=x;//TODO
			}
		}
		printf("%d\n",answer);
	}
	
	return 0;
}
