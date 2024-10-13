#include<stdio.h>
#include<string.h>
int mystrstr(char a[], char b[]);
int main(){
	int c;
	char a[500]="";
	char b[500]="";
	gets(a);
	gets(b);
	c=mystrstr(a,b);
	printf("%d",c);
	return 0;
}
int mystrstr(char a[], char b[]){
	int i,ret=0;
	for(i=0;i<strlen(a);i++){
		for(int x=0;x<strlen(b);x++){
			if(a[i+x]!=b[x]){
				ret=1;
				break;
			}
			else{
				ret=0;
			}
		}
		if(ret==0){
			break;
		}
	}
	if(ret==1){
		i=-1;
	}
	return i;
}
