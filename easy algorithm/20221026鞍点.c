#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[100][100]={0};
	int i=0,j=0;
	int x=0,y=0; 
	int b=0,c=0;
	int t,h=0;
	for(x=0;x<n;x++){
		for(y=0;y<n;y++){
			scanf("%d",&a[x][y]);	//TODO
		}	//TODO
	}
	x=n-1,y=n-1;
	for(i=0;i<=x;i++){
		t=a[i][0];
		for(j=0;j<=y;j++){
			if(a[i][j]>t){
				t=a[i][j];
			}			
		}//找出一行中的最大
		for(j=0;j<=y;j++){				
			if(a[i][j]==t){
				c=j;
				h=1;//判断是否是那个最大值，是就仔判断列上是否最小
				for(b=0;b<=x;b++){
					if(t>a[b][c]){
						h=0;
						break;
					}
				}	//TODO
			}//TODO
			if(h==1){
				break;//TODO
			}
		}
		if(h==1){
			break;//TODO
		}
	}
	if(h==0){
		printf("NO");//TODO
	}
	else{
		printf("%d %d",i,c);
	}
	return 0;
}
