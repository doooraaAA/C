//4: ��ĩ���
//��������ĩ����ϣ���ʿ�Ǻ�Ůʿ�ǽ�������ʱ�������ų�һ�ӡ����迪ʼʱ�����δ��жӺ�Ů�ӵĶ�ͷ�ϸ���һ�������顣�涨ÿ����������һ�������ߡ������ӳ�ʼ��������ͬ����ϳ�����һ����δ����ߵȴ���һ����������Ҫ��дһ������ģ���������������⡣
//����
//��һ����������������ʾ��ʿ���� mm ��Ůʿ���� nn��1 \le m, n \le 10001��m, n��1000��
//�ڶ���һ������������ʾ��������Ŀ kk��k \leq 1000k��1000��
//���
//�� kk �У�ÿ����������֮����һ���ո��������ʾ���������ţ���ʿ��ǰ��Ůʿ�ں�
//����
//2 4
//6
//���
//1 1
//2 2
//1 3
//2 4
//1 1
//2 2
//��ʾ
//��Ҫ��������ѭ�����С�
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
typedef struct {
	int* base;
	int front;
	int rear;
}SqQueue;

SqQueue InitQueue(SqQueue &Q, int n);//������
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