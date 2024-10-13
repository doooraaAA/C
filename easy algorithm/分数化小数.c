#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		double a,b,c;
		scanf("%lf %lf %lf",&a,&b,&c);
		if(a>=2&&b<=10000000){
			long double x=a/b;//x为计算得原始数据
			int d=x*pow(10,c+1);//d用于判断四舍五入
			int h;//h为四舍五入后的用于转化为小数
			double answer;//answer为最终输出答案
			if(d%10>=5){
			h=d/10+1;	
			}
			else{
				h=d/10;
			}
			answer=h*pow(0.1,c);
			printf("%lf",answer);
		}//TODO
	}
	return 0;
}
