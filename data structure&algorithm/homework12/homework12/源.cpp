//2: ��ջ���ջ
//����һ�����������У���0��ʾ������������ӵ�һ������ʼ����ÿһ������ջ����ջ��ͬʱ���һ������������������ֵ������ջ��ջ�Ĵ�С������㽫����Ԫ����ջ��ķ����ͣ�Ȼ��ջ��Ԫ�����������Ҫ��ʹ��˳��ջ��Ԫ�ظ��� < 100��ÿ��Ԫ�� < 100��
//	����
//	һ�У�һ�����������У���0��β��
//	���
//	���У���һ��Ϊһ������������ʾ�����͡�
//	�ڶ���Ϊ������Ԫ�س�ջ��Ľ�����ո�ָ�
//	�����������
//	����	5 4 3 2 1 0
//	���	35	1 2 3 4 5
#define _CRT_SECURE_NO_WARNINGS
#define OVERFLOW -1
#define OK 1
#define ERROR -1
#include<iostream>
#include"stdio.h"
#include "malloc.h"
typedef int Status;
typedef struct {
	int *base;
	int* top;
	int stacksize;
}SqStack;

Status Init(SqStack& s) {
	s.base = new int[100];
	if (!s.base) return OVERFLOW;
	s.top = s.base;
	s.stacksize = 100;
	return OK;
}
Status Push(SqStack& s) {
	int e;
	int a=0;
	int sum = 0;
	while (1) {
		scanf("%d", &e);
		if (e == 0)break;
		if (s.top - s.base == s.stacksize)
			return OVERFLOW;
		*s.top = e;
		s.top++;
		a = s.top - s.base;
		a = a * e;
		sum = sum + a;
		
	}
	return sum;
}//��ջ�Ҽ�����������ط���
Status Pop(SqStack& s) {
	if (s.top == s.base)
		return ERROR;
	s.top--;
	return OK;
}//��ջ
Status GetTop(SqStack& s) {
	if (s.top != s.base)
		return *(s.top - 1);
}//��ȡջ��Ԫ��

int main(void) {
	int n = 1;
	int sum=0;
	SqStack s;
	Init(s);
	sum = Push(s);
	printf("%d\n", sum);
	int ans;
	while (s.top != s.base) {
		ans = GetTop(s);
		Pop(s);
		printf("%d ", ans);
	}
}