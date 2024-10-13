#include<stdio.h>
int main(){
	int n;
	int a,b,c;
	double d;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(a>=2&&b<=10000000)
			d=a/b;
		printf("%.clf\n",d);
	}
	return 0;
}
