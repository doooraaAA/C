#include<stdio.h>
void move1(char,char,int);
void hanoi(int n,char A,char B,char C);
int main(){
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
}
void hanoi(int n,char A,char B,char C){
	if(n==1){
		move1(A,C,n);
	}
	else{
		hanoi(n-1,A,C,B);
		move1(A,C,n);
		hanoi(n-1,B,A,C);
	}
}
void move1(char A,char B,int n){
	static int i=0;
	i++;
	printf("Step%d: Move Disk%d from %c to %c\n",i,n,A,B);
}
