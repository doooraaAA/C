#include<stdio.h>
#include<string.h>
int main(){
	char sentence[1000]="";
	gets(sentence);
	int a=0,sum=0,b=0;
	for(int i=0;i<strlen(sentence);i++){
		if(sentence[i]!='.'){
			if(sentence[i]!=' '){
				a++;
			}
			else{
				sum+=a;
				if(a!=0){
					printf("%d ",a);//TODO
				}
				a=0;
				b++;
			}
		}
	}
	printf("%d",strlen(sentence)-sum-b-1);
	return 0;
}
