#include<stdio.h>
int fun(double a,double ans);
int main(){
	double a,ans=1,ans2=1;
	int n;
	scanf("%lf,%d",&a,&n);
	if(n>=1){
		for(int i=1;i<=n;i++){
			ans=fun(a,ans);
		}
		printf("%lf",ans);
	}
	else if(n==0&&a!=0){
		printf("1");
	}
	else if(n<0){
		for(int i=1;i<=(-n);i++){
			ans2=ans2/a;
		}
		printf("%lf",ans2);
	}
	return 0;
}
int fun(double a,double ans){
	ans=ans*a;
	return ans;
}
