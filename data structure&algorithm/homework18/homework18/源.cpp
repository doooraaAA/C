//8: 循环队列
//描述
//请你实现一个循环队列，该循环队列可利用的空间大小等于n个int型变量的大小。
//操作：
//push x：将x加入到循环队列尾端。若循环队列已满，输出"full"(不含引号)，否则不输出任何内容。保证x为int型整数。
//front：输出队首元素，队首不出队。若队列为空，输出"empty"(不含引号)。
//pop：输出队首元素，且队首出队。若队列为空，输出"empty"(不含引号)
//输入
//第一行输入两个整数n, q(1≤n, q≤105)，表示循环队列可利用的空间大小和操作次数。
//接下来的q行，每行一个字符串，表示一个操作。保证操作是题目描述中的一种
//输出
//按照题目描述中的要求输出
//输入输出样例
//输入
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
//输出
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
	return Q;//初始化队列
}
SqQueue OutQueue(SqQueue& Q,int n) {
	if (Q.front == Q.rear)printf("empty\n");
	else {
		printf("%d\n", Q.base[Q.front]);
	Q.front = (Q.front + 1) % n;
	}	
	return Q;
}//出队

SqQueue InQueue(SqQueue& Q, int e,int n) {
	if ((Q.rear +1- Q.front + n) % n == 0) printf("full\n");
	else{Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % n;}
	return Q;
}//入队
SqQueue GetQueue(SqQueue& Q) {
	if (Q.front == Q.rear) printf("empty\n");
	else printf("%d\n", Q.base[Q.front]);
	return Q;
}//获取对头元素

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