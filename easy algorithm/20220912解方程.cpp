#include<stdio.h>
#include<math.h>
int main()
{	double a,b,c;
	while (scanf("%d,%d,%d",&a,&b,&c)==3){
	if(a!=0){
		double delta=b*b-4*a*c;//����delta���жϽ�ĸ���
		if(delta>0){
			double x1=(-b+sqrt(delta))/(2*a);
			double x2=(-b-sqrt(delta))/(2*a);
			if(x1<x2){
				printf("%.2lf,%.2lf\n",x2,x1); 
			}
			else{
			printf("%.2lf %.2lf\n",x1,x2);
			}
		}//���ָ������ 
		else if (delta==0){
		printf("%.2lf\n",-b/(2*a));
		}//����ȵ���� 
		else{
		printf("x\n");
		}
	}
	else {
		if(b==0){
			printf("x\n");
		}
		else{
			printf("%.2lf\n",(-c/b));
		}
	} 
	}
	return 0;	
}
