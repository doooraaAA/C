//7: ջ��ѹ�롢��������
//������������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С�
//ջ�����ݵ�������1000
//2. push ���������־�����ͬ
//����
//����Ϊ���У�ÿ�а���һ���������У��ÿո������ - 1�����������������зֱ��ʾջ��ѹ��˳���뵯��˳��
//���
//���Ϊtrue / false��ʾ�ڶ��������ܷ�Ϊ��ջ�ĵ���˳��
//�����������
//����
//1 2 3 4 5 - 1
//4 5 3 2 1 - 1
//���
//true
#define _CRT_SECURE_NO_WARNINGS
#define OVERFLOW -1
#define OK 1
#include<iostream>
#include"stdio.h"
#include "malloc.h"
#include<string.h>
typedef int Status;
typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;

Status Init(SqStack& s) {
	s.base = new int[100];
	if (!s.base) return OVERFLOW;
	s.top = s.base;
	s.stacksize = 100;
	return OK;
}//��ʼ��
Status Push(SqStack& s, int e) {
	if (s.top - s.base == s.stacksize)
		return OVERFLOW;
	*s.top = e;
	s.top++;
	return OK;
}//��ջ
Status Pop(SqStack& s) {
	if (s.top != s.base)
	s.top--;
	return OK;
}//��ջ
Status GetTop(SqStack& s) {
	if (s.top != s.base)
		return *(s.top - 1);
	else return -1;
}//��ȡջ��Ԫ��

int main(void) {
	SqStack S;
	Init(S);
	int push[1000];
	int a = 0,b=0;
	while (1)
	{
		scanf("%d", &b);
		push[a] = b;
		if (b == -1)break;
		a++;
	}
	
	int pop[1000];
	a = 0;
	while (1)
	{
		scanf("%d", &b);
		if (b == -1)break;
		pop[a] = b;
		a++;
	}
	b = a - 1;//bΪ����
	a = 0;
	int i = 0;
	while (1) {
		if (push[i] == -1) break;
		Push(S, push[i]);
		while (pop[a] == GetTop(S)) {
			Pop(S);
			a++;
		}
		i++;
	}
	if (GetTop(S)==-1) printf("true");
	else printf("false");
}