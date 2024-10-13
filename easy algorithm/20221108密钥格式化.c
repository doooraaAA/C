#include<stdio.h>
#include<string.h>
int main(){
	char S[10000]="";
	char ans[10000]="";
	gets(S);
	int K,b,a=0;
	scanf("%d",&K);
	int t=strlen(S);
	for(int i=0;i<t;i++){
		if(S[i]!='-'){
			if('a'<=S[i]&&S[i]<='z'){
				ans[a]=S[i]-32;
			}
			else{
				ans[a]=S[i];
			}
			a++;
		}
	}
	b=a%K;
	if(b!=0){
		for(int i=0;i<b;i++){
			printf("%c",ans[i]);
		}
		for(int i=1;i<=a/K;i++){
			printf("-");
			for(int n=b+(i-1)*K;n<K*i+b;n++){
				printf("%c",ans[n]);
			}
		}
	}
	else{
		for(int i=0;i<K;i++){
		printf("%c",ans[i]);
		}
		for(int i=1;i<a/K;i++){
			printf("-");
			for(int n=K*i;n<K*(i+1);n++){
				printf("%c",ans[n]);
			}
		}
	}
	
	return 0;
}
