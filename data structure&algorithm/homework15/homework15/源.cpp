//5: 无法吃午餐的学生数量
//学校的自助午餐提供圆形和方形的三明治，分别用数字 0 和 1 表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个 栈 里，每一轮：
//1.如果队列最前面的学生 喜欢 栈顶的三明治，那么会 拿走它 并离开队列。
//否则，这名学生会 放弃这个三明治 并回到队列的尾部。
//2.这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。
//输入两个整数数组 students 和 sandwiches ，其中 sandwiches[i] 是栈里面第 i个三明治的类型（i = 0 是栈的顶部）， students[j] 是初始队列里第 j名学生对三明治的喜好（j = 0 是队列的最开始位置）。请你返回无法吃午餐的学生数量。
//输入
//输入为两行，第一个行重数字表示学生对三明治的喜好（ - 1表示结束），第二个行中数字表示三明治的顺序（ - 1表示结束），数组中元素数量均 < 100
//	输出
//	输出为一个整数，表示无法吃午餐的学生的数量
//	输入输出样例
//	输入
//	1 1 1 0 0 1 - 1
//	1 0 0 0 1 1 - 1
//	输出
//	3
//	解释：
//	最前面的学生拿走栈顶三明治离开，剩余学生队列为[1, 1, 0, 0, 1]，三明治栈为[0, 0, 0, 1, 1]；
//	最前面学生放弃栈顶三明治，排到队尾，剩余学生队列为[1, 0, 0, 1, 1]，三明治栈为[0, 0, 0, 1, 1]；
//	最前面学生放弃栈顶三明治，排到队尾，, 剩余学生队列为[1, 0, 0, 1, 1]，三明治栈为[0, 0, 0, 1, 1]；
//	最前面学生放弃栈顶三明治，排到队尾，, 剩余学生队列为[0, 0, 1, 1, 1]，三明治栈为[0, 0, 0, 1, 1]；
//	最前面的学生拿走栈顶三明治离开，剩余学生队列为[0, 1, 1, 1]，三明治栈为[0, 0, 1, 1]；
//	最前面的学生拿走栈顶三明治离开，剩余学生队列为[1, 1, 1]，三明治栈为[0, 1, 1]；
//	剩余三名学生无法吃到午饭
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
}//初始化
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
}//入栈

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
	return Q;//初始化队列
}

SqQueue OutQueue(SqQueue& Q) {
	Q.front = (Q.front + 1) % 100;
	return Q;
}//出队

SqQueue InQueue(SqQueue& Q,int e) {
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % 100;
	return Q;
}//入队

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