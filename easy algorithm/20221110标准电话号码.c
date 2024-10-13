#include<stdio.h>
#include<string.h>
int main(){
	char str[7]="";
	gets(str);
	for(int i=0;i<=6;i++){
	if(65<=str[i]&&str[i]<=67){
		printf("2");
	}
	else if(68<=str[i]&&str[i]<=70){
		printf("3");
	}
	else if(71<=str[i]&&str[i]<=73){
		printf("4");
	}
	else if(74<=str[i]&&str[i]<=76){
		printf("5");
	}
	else if(77<=str[i]&&str[i]<=79){
		printf("6");
	}
	else if(80<=str[i]&&str[i]<=83){
		printf("7");
	}
	else if(84<=str[i]&&str[i]<=86){
		printf("8");
	}
	else if(87<=str[i]&&str[i]<=90){
		printf("9");
	}	
	}
	return 0;
}
