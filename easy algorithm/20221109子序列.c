#include<stdio.h>
#include<string.h>
int main(){
	int ret=0,a=0;
	char s[500]="";
	char t[500]="";
	gets(s);
	gets(t);
	for(int i=0;i<strlen(t);i++){
		ret=0;
		for(int x=a+1;x<strlen(s);x++){
			if(s[x]==t[i]){
				ret=1;
				a=x;
				break;
			}
		}
		if(ret==0){
			break;
		}
	}
	if(ret==1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
