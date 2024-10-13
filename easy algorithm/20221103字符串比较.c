#include<stdio.h>
#include<string.h>
int main() {
	char s1[10001]="";
	char s2[10001]="";
	char *a=NULL;
	int ret=-1;	
	int*num[10001]={0};
	int x=0;
	gets(s1);
	gets(s2);
	int t=strlen(s2);
	int i=0;
	if(strlen(s1)<=strlen(s2)){
		while(i<t){
			a=strstr(&s2[i],s1);
			if(a!=NULL){
			ret=1;
			i=a-&s2[0];
			num[x]=i;
			x++;
			i++;
			}
			else{i=t;}
		}
		if(ret==-1){
			printf("-1");
		}
		else{
			for(i=0;i<x-1;i++){
				printf("%d ",num[i]);
			}
			printf("%d",num[x-1]);
		}
		printf("\n");
	}
	return 0;
}
