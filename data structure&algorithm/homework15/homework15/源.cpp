//5: �޷�����͵�ѧ������
//ѧУ����������ṩԲ�κͷ��ε������Σ��ֱ������� 0 �� 1 ��ʾ������ѧ��վ��һ�������ÿ��ѧ��Ҫôϲ��Բ�ε�Ҫôϲ�����εġ������������ε�������ѧ����������ͬ�����������ζ�����һ�� ջ �ÿһ�֣�
//1.���������ǰ���ѧ�� ϲ�� ջ���������Σ���ô�� ������ ���뿪���С�
//��������ѧ���� ������������� ���ص����е�β����
//2.������̻�һֱ����������������ѧ������ϲ��ջ����������Ϊֹ��
//���������������� students �� sandwiches ������ sandwiches[i] ��ջ����� i�������ε����ͣ�i = 0 ��ջ�Ķ������� students[j] �ǳ�ʼ������� j��ѧ���������ε�ϲ�ã�j = 0 �Ƕ��е��ʼλ�ã������㷵���޷�����͵�ѧ��������
//����
//����Ϊ���У���һ���������ֱ�ʾѧ���������ε�ϲ�ã� - 1��ʾ���������ڶ����������ֱ�ʾ�����ε�˳�� - 1��ʾ��������������Ԫ�������� < 100
//	���
//	���Ϊһ����������ʾ�޷�����͵�ѧ��������
//	�����������
//	����
//	1 1 1 0 0 1 - 1
//	1 0 0 0 1 1 - 1
//	���
//	3
//	���ͣ�
//	��ǰ���ѧ������ջ���������뿪��ʣ��ѧ������Ϊ[1, 1, 0, 0, 1]��������ջΪ[0, 0, 0, 1, 1]��
//	��ǰ��ѧ������ջ�������Σ��ŵ���β��ʣ��ѧ������Ϊ[1, 0, 0, 1, 1]��������ջΪ[0, 0, 0, 1, 1]��
//	��ǰ��ѧ������ջ�������Σ��ŵ���β��, ʣ��ѧ������Ϊ[1, 0, 0, 1, 1]��������ջΪ[0, 0, 0, 1, 1]��
//	��ǰ��ѧ������ջ�������Σ��ŵ���β��, ʣ��ѧ������Ϊ[0, 0, 1, 1, 1]��������ջΪ[0, 0, 0, 1, 1]��
//	��ǰ���ѧ������ջ���������뿪��ʣ��ѧ������Ϊ[0, 1, 1, 1]��������ջΪ[0, 0, 1, 1]��
//	��ǰ���ѧ������ջ���������뿪��ʣ��ѧ������Ϊ[1, 1, 1]��������ջΪ[0, 1, 1]��
//	ʣ������ѧ���޷��Ե��緹
#define _CRT_SECURE_NO_WARNINGS
#define OVERFLOW -1
#define OK 1
#define ERROR -2
#include<iostream>
#include"stdio.h"
typedef int Status;
typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;
typedef struct {
	int* base;
	int front;
	int rear;
}SqQueue;

Status Init(SqStack& s) {
	s.base = new int[100];
	if (!s.base) return OVERFLOW;
	s.top = s.base;
	s.stacksize = 100;
	return OK;
}//��ʼ��
Status Push(SqStack& s) {
	int e;
	int a[100];
	int i = 0;
	while (1) {
		scanf("%d", &e);
		if (e == -1)break;
		a[i] = e;
		i++;
	}
	while (i)
	{
		if (s.top - s.base == s.stacksize)
			return OVERFLOW;
		*s.top = a[i - 1];
		s.top++;
		i--;
	}
	return OK;
}//��ջ

SqQueue InitQueue(SqQueue& Q) {

	Q.base = new int[100];
	Q.front = Q.rear = 0;
	int i ;
	while (1)
	{
		scanf("%d", &i);
		if (i == -1) break;
		if ((Q.rear + 1) % (100 + 1) == Q.front) break;
		Q.base[Q.rear] = i;
		Q.rear = (Q.rear + 1) % 100;
	}
	return Q;//��ʼ������
}

SqQueue OutQueue(SqQueue& Q) {
	Q.front = (Q.front + 1) % 100;
	return Q;
}//����

SqQueue InQueue(SqQueue& Q,int e) {
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % 100;
	return Q;
}//���

int Match(SqQueue &Q, SqStack &S) {
	
		int a = Q.base[Q.front];
		int b = *(S.top-1);
		int tag = 0;
		if (a == b) {
			S.top=S.top-1;
			OutQueue(Q);
			tag = 1;
		}
		else {
			OutQueue(Q);
			InQueue(Q, a);
			tag = 0;
		}
		return tag;
}
int main(void) {
	SqQueue Q;
	InitQueue(Q);
	SqStack S;
	Init(S);
	Push(S);
	while (1)
	{
		int n = (Q.rear - Q.front + 100) % 100;
		int tag=0;
		while (n)
		{
			n--;
			tag = tag + Match(Q, S);
		}
		if (tag == 0) break;
	}
	printf("%d", (Q.rear - Q.front + 100) % 100);
	return 0;
}