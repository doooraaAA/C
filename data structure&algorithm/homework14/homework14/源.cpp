//4: 周末舞会
//假设在周末舞会上，男士们和女士们进入舞厅时，各自排成一队。跳舞开始时，依次从男队和女队的队头上各出一人配成舞伴。规定每个舞曲能有一对跳舞者。若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。现要求写一个程序，模拟上述舞伴配对问题。
//输入
//第一行两个正整数，表示男士人数 mm 和女士人数 nn，1 \le m, n \le 10001≤m, n≤1000；
//第二行一个正整数，表示舞曲的数目 kk，k \leq 1000k≤1000。
//输出
//共 kk 行，每行两个数，之间用一个空格隔开，表示配对舞伴的序号，男士在前，女士在后。
//输入
//2 4
//6
//输出
//1 1
//2 2
//1 3
//2 4
//1 1
//2 2
//提示
//需要建立两个循环队列。
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
typedef struct {
	int* base;
	int front;
	int rear;
}SqQueue;

SqQueue InitQueue(SqQueue &Q, int n);//创建队
void MatchQueue(SqQueue Q1, SqQueue Q2,int m,int n,int k);

int main(void) {
	SqQueue Q1,Q2;
	int m, n;
	scanf("%d %d", &m ,&n);
	Q1 = InitQueue(Q1,m);
	Q2 = InitQueue(Q2,n);
	int k;
	scanf("%d", &k);
	MatchQueue(Q1, Q2,m,n,k);
	return 0;
}

SqQueue InitQueue(SqQueue& Q, int n) {

	Q.base = new int[n];
	Q.front = Q.rear=0;
	int i = 1;
	while (i<=n)
	{
		if ((Q.rear + 1) % (n+1) == Q.front) break;
		Q.base[Q.rear] = i;
		Q.rear = (Q.rear + 1) % n;
		i++;
	}
	return Q;
}
void MatchQueue(SqQueue Q1, SqQueue Q2,int m,int n,int k) {
	while (k)
	{
		int a = Q1.base[Q1.front];
		Q1.front = (Q1.front + 1) % m;
		int b = Q2.base[Q2.front];
		Q2.front = (Q2.front + 1) % n;
		printf("%d %d\n", a, b);
		Q1.base[Q1.rear] = a;
		Q1.rear = (Q1.rear + 1) % (m );
		Q2.base[Q2.rear] = b;
		Q2.rear = (Q2.rear + 1) % (n);
		k--;
	}
}