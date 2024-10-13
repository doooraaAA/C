#include<stdio.h>
int gcd(int,int);
int lcm(int,int);
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int c=gcd(a,b);
	int d=lcm(a,b);
	printf("%d\n",c);
	printf("%d",d);
	return 0;
}
int gcd(int a,int b){
	int c;
	for(int i=1;i<=a&&i<=b;i++){
		if(a%i==0&&b%i==0){
		c=i;//TODO
		}
	}
	return c;
}
int lcm(int a,int b){
	int c,d;
	if(a>b){
		d=a;//TODO
	}
	else{
		d=b;
	}
	for(int i=d;i>=d;i++){
		if(i%a==0&&i%b==0){
			c=i;
			break;//TODO
		}
	}
	return c;
}
