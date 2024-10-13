#include<stdio.h>
#include<string.h>
int mystrcmp(char *a,char *b);
int main(){
	char a[501]="";
	char b[501]="";
	gets(a);
	gets(b);
	printf("%d",mystrcmp(a,b));
	return 0;
}
int mystrcmp(char *a,char *b){
	int ret;
	for(int i=0;i<strlen(a)||i<strlen(b);i++){
		if(a[i]==b[i]){
			ret=0;
		}
		else if(a[i]<b[i]){
			ret=-1;
			break;
		}
		else{
			ret=1;
			break;
		}
	}
	return ret;
}
