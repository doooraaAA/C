#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "stdio.h"
#include "malloc.h"
#define OK 1
#define OVERFLOW -1
#define ERROR 0
#define QMAXSIZE 23//定义长度，长度>=输出行数+3
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType* base;  //初始化的动态分配存储空间
	int   front;     //头指针，队列不空指向队列头元素
	int   rear;      //尾指针，队列不空指向队列尾元素下一位置
}SqQueue;

Status InitQueue(SqQueue& Q)
{//构造空队列
	Q.base = new ElemType[QMAXSIZE];
	if (!Q.base)
		return OVERFLOW;
	Q.front = Q.rear = 0;
	return OK;


}

Status QueueLength(SqQueue Q)
{//获取队列长度
	return (Q.rear - Q.front + QMAXSIZE) % QMAXSIZE;

}

void GetHead(SqQueue Q, ElemType& e)
{//返回队头元素
	if (Q.front == Q.rear)
		e = 0;
	else
		e = Q.base[Q.front];
}

Status EnQueue(SqQueue& Q, ElemType e)
{//插入元素
	if ((Q.rear + 1) % QMAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % QMAXSIZE;
	return OK;

}

Status DeQueue(SqQueue& Q, ElemType& e)
{//删除元素

	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % QMAXSIZE;
	return OK;
}

Status QueueEmpty(SqQueue& Q)
{//判断队列是否为空
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}


void PrintQueue(SqQueue Q, ElemType n)
{//遍历循环队列，并打印所有元素

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
{//杨辉三角
	SqQueue Q;
	ElemType j, s, t;
	printf("第1行：1\n");
	InitQueue(Q);
	EnQueue(Q, 0);  /*开始*/
	EnQueue(Q, 1);  /*第1行*/
	EnQueue(Q, 1);
	for (j = 2; j < n; j++)  //从第二行开始循环到n-1行
	{
		EnQueue(Q, 0); /*第j行的结束符*/
		printf("第%d行：", j);
		do
		{
			DeQueue(Q, s);
			GetHead(Q, t);
			if (t)
				printf("%d\t", t); /*非0输出，否则换行*/
			else
				printf("\n");
			EnQueue(Q, s + t);
		} while (t != 0);  /*遇到结束符前循环*/
	}
	DeQueue(Q, s); //输出最后一行
	printf("第%d行：", j);
	PrintQueue(Q, j);
}

void main()
{
	ElemType n;
	while (true)
	{
		printf("请输入输出的行数(小于等于%d)：", QMAXSIZE - 3);
		scanf("%d", &n);
		if (n <= (QMAXSIZE - 3) && n > 1)
		{
			YangHui(n);
			break;
		}
		else
			printf("输入错误，请重新输入\n");
	}
}
