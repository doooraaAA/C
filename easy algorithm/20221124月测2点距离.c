#include<stdio.h>
#include<math.h>
struct len{
	char name1[30];
	int x1;
	int y1;
	char name2[30];
	int x2;
	int y2;
};
int main(){
	struct len point[100];
	int i=0;
	int a;
	float ans[2][100]={0};
	while(scanf("%s %d %d %s %d %d",&point[i].name1,&point[i].x1,&point[i].y1,&point[i].name2,&point[i].x2,&point[i].y2)!=EOF){
		a=pow(point[i].x1-point[i].x2,2)+pow(point[i].y1-point[i].y2,2);
		ans[1][i]=sqrt(a);
		ans[0][i]=i;
		i++;
	}
	for(int x=0;x<i;x++){
		for(int t=0;t<i;t++){
			if(ans[1][x]>ans[1][t]){
				float swi=ans[1][t];
				int swi2=ans[0][t];
				ans[1][t]=ans[1][x];
				ans[1][x]=swi;
				ans[0][t]=ans[0][x];
				ans[0][x]=swi2;
			}
		}
	}
	for(int x=0;x<i;x++){
		printf("%s %s %.2f\n",point[(int)ans[0][x]].name1,point[(int)ans[0][x]].name2,ans[1][x]);
	}
	return 0;
}
