//8: ѭ������
//����
//����ʵ��һ��ѭ�����У���ѭ�����п����õĿռ��С����n��int�ͱ����Ĵ�С��
//������
//push x����x���뵽ѭ������β�ˡ���ѭ���������������"full"(��������)����������κ����ݡ���֤xΪint��������
//front���������Ԫ�أ����ײ����ӡ�������Ϊ�գ����"empty"(��������)��
//pop���������Ԫ�أ��Ҷ��׳��ӡ�������Ϊ�գ����"empty"(��������)
//����
//��һ��������������n, q(1��n, q��105)����ʾѭ�����п����õĿռ��С�Ͳ���������
//��������q�У�ÿ��һ���ַ�������ʾһ����������֤��������Ŀ�����е�һ��
//���
//������Ŀ�����е�Ҫ�����
//�����������
//����
//3 10
//push 1
//push 2
//front
//push 3
//push 4
//pop
//pop
//pop
//front
//pop
//���
//1
//full
//1
//2
//3
//empty
//empty
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include "malloc.h"
#include<string.h>
typedef int Status;
typedef struct {
	int* base;
	int front;
	int rear;
}SqQueue;
SqQueue InitQueue(SqQueue& Q,int n) {

	Q.base = new int[n];
	Q.front = Q.rear = 0;
	return Q;//��ʼ������
}
SqQueue OutQueue(SqQueue& Q,int n) {
	if (Q.front == Q.rear)printf("empty\n");
	else {
		printf("%d\n", Q.base[Q.front]);
	Q.front = (Q.front + 1) % n;
	}	
	return Q;
}//����

SqQueue InQueue(SqQueue& Q, int e,int n) {
	if ((Q.rear +1- Q.front + n) % n == 0) printf("full\n");
	else{Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % n;}
	return Q;
}//���
SqQueue GetQueue(SqQueue& Q) {
	if (Q.front == Q.rear) printf("empty\n");
	else printf("%d\n", Q.base[Q.front]);
	return Q;
}//��ȡ��ͷԪ��

int main(void) {
	int n = 0, q = 0;
	scanf("%d %d", &n, &q);
	n = n + 1;
	SqQueue Q;
	InitQueue(Q,n);
	while (q)
	{
		q--;
		char str[100];
		scanf("%s", &str);
		if (!strcmp(str, "push")) {
			int e = 0;
			scanf("%d", &e);
			InQueue(Q, e,n);
		}
		if (!strcmp(str, "pop")) {
			OutQueue(Q,n);
		}
		if (!strcmp(str, "front")) {
			GetQueue(Q);
		}
	}
	return 0;
}