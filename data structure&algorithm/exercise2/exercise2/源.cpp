#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "stdio.h"
#include "malloc.h"
#define OK 1
#define OVERFLOW -1
#define ERROR 0
#define QMAXSIZE 23//���峤�ȣ�����>=�������+3
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType* base;  //��ʼ���Ķ�̬����洢�ռ�
	int   front;     //ͷָ�룬���в���ָ�����ͷԪ��
	int   rear;      //βָ�룬���в���ָ�����βԪ����һλ��
}SqQueue;

Status InitQueue(SqQueue& Q)
{//����ն���
	Q.base = new ElemType[QMAXSIZE];
	if (!Q.base)
		return OVERFLOW;
	Q.front = Q.rear = 0;
	return OK;


}

Status QueueLength(SqQueue Q)
{//��ȡ���г���
	return (Q.rear - Q.front + QMAXSIZE) % QMAXSIZE;

}

void GetHead(SqQueue Q, ElemType& e)
{//���ض�ͷԪ��
	if (Q.front == Q.rear)
		e = 0;
	else
		e = Q.base[Q.front];
}

Status EnQueue(SqQueue& Q, ElemType e)
{//����Ԫ��
	if ((Q.rear + 1) % QMAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % QMAXSIZE;
	return OK;

}

Status DeQueue(SqQueue& Q, ElemType& e)
{//ɾ��Ԫ��

	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % QMAXSIZE;
	return OK;
}

Status QueueEmpty(SqQueue& Q)
{//�ж϶����Ƿ�Ϊ��
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}


void PrintQueue(SqQueue Q, ElemType n)
{//����ѭ�����У�����ӡ����Ԫ��

	int count = 1;

	while (count <= n)
	{
		ElemType e;
		DeQueue(Q, e);
		printf("%d \t", e);
		count++;
	}
	printf("\n");

}

void YangHui(int n)
{//�������
	SqQueue Q;
	ElemType j, s, t;
	printf("��1�У�1\n");
	InitQueue(Q);
	EnQueue(Q, 0);  /*��ʼ*/
	EnQueue(Q, 1);  /*��1��*/
	EnQueue(Q, 1);
	for (j = 2; j < n; j++)  //�ӵڶ��п�ʼѭ����n-1��
	{
		EnQueue(Q, 0); /*��j�еĽ�����*/
		printf("��%d�У�", j);
		do
		{
			DeQueue(Q, s);
			GetHead(Q, t);
			if (t)
				printf("%d\t", t); /*��0�����������*/
			else
				printf("\n");
			EnQueue(Q, s + t);
		} while (t != 0);  /*����������ǰѭ��*/
	}
	DeQueue(Q, s); //������һ��
	printf("��%d�У�", j);
	PrintQueue(Q, j);
}

void main()
{
	ElemType n;
	while (true)
	{
		printf("���������������(С�ڵ���%d)��", QMAXSIZE - 3);
		scanf("%d", &n);
		if (n <= (QMAXSIZE - 3) && n > 1)
		{
			YangHui(n);
			break;
		}
		else
			printf("�����������������\n");
	}
}
