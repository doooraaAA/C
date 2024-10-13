//6: ջ�Ĳ���
//����
//����ʵ��һ��ջ��
//������ɲ�����
//push x���� x��ջ����֤ xΪ int ��������
//pop�����ջ��������ջ����ջ
//top�����ջ����ջ������ջ
//����
//��һ��Ϊһ�������� n���������������(1��n��10000)
//�������� n�� ��ÿ��Ϊһ���ַ���������һ����������֤��������Ŀ�����������е�һ�֡�
//���
//�������Ϊpush��������κζ�����
//���Ϊ�������֣���ջΪ�գ������ "error��
//���򰴶�Ӧ���������
//�����������
//����
//6
//push 1
//pop
//top
//push 2
//push 3
//pop
//���
//1
//error
//3
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
}
Status Push(SqStack& s,int e) {
	int a = 0;
		if (s.top - s.base == s.stacksize)
			return OVERFLOW;
		*s.top = e;
		s.top++;
	return OK;
}//��ջ�Ҽ�����������ط���
Status Pop(SqStack& s) {
	if (s.top == s.base)
		printf("error\n");
	else {
		printf("%d\n", *(s.top - 1));
		s.top--;
	}
	return OK;
}//��ջ
Status GetTop(SqStack& s) {
	if (s.top == s.base)
		printf("error\n");
	else
		printf("%d\n",* (s.top - 1));
	return OK;
}//��ȡջ��Ԫ��

int main(void) {
	int n = 0;
	scanf("%d", &n);
	SqStack S;
	Init(S);
	while (n)
	{
		n--;
		char str[400];
		scanf("%s", &str);
		if (!strcmp(str, "push")) {
			int e = 0;
			scanf("%d", &e);
			Push(S,e);
		}
		if (!strcmp(str, "pop")) {
			Pop(S);
		}
		if (!strcmp(str, "top")) {
			GetTop(S);
		}
	}
	return 0;
}