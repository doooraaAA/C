#include<stdio.h>
#include<math.h>
int main(){
	int n;//循环n次
	int a,m,x=0;
	int result;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		result=0;
		scanf("%d",&a);
		while(a>0){
			m=a%2;
			a=a/2;
			if(m==1){
				result++;//TODO
			}
			x++;
		}
		printf("%d\n",result);
		}
	return 0;
}
