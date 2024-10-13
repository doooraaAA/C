#include <stdio.h>
int main()
{
	int i,n;
	int a,j,k,l,m,x;
	scanf("%d",&n);//输入n组数据
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);//输入整数a 
		j=a;
		k=a;
		l=a;
		m=a;
		x=a;
		for(j=a;j<=a+4;j++){
			for(k=a;k<=a+4;k++){
				for(l=a;l<=a+4;l++){
					for(m=a;m<=a+4;m++){
						for(x=a;x<=a+4;x++){
							if(j!=k&&j!=l&&j!=m&&j!=x&&k!=l&&k!=m&&k!=x&&l!=m&&l!=x&&m!=x)
								printf("%d%d%d%d%d\n",j,k,l,m,x);	
						}
					}
				}
			}
		}
	} 
	return 0;
}

