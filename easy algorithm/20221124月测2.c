#include<stdio.h>
#include<string.h>
int main(){
	char a[500]="";
	char b[500]="";
	int n,t=0;
	scanf("%d",&n);
	gets(a);
	for(int i=0;i<n;i++){
		gets(a);
		for(int j=0;j<strlen(a);j++){
		if('a'<=a[j]&&a[j]<='z'){
		b[t]=a[j];
		t++;
		}	
		}
		int j=strlen(b)-1;
		int x=0;
		while(j!=x&&i!=x-2){
			char swi=b[j];
			b[j]=b[x];
			b[x]=swi;
			j--;
			x++;
		}
		printf("%s\n",b);
	}
	return 0;
}
