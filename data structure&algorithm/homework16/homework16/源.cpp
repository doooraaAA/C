//6: 栈的操作
//描述
//请你实现一个栈。
//可以完成操作：
//push x：将 x入栈，保证 x为 int 型整数。
//pop：输出栈顶，并让栈顶出栈
//top：输出栈顶，栈顶不出栈
//输入
//第一行为一个正整数 n，代表操作次数。(1≤n≤10000)
//接下来的 n行 ，每行为一个字符串，代表一个操作。保证操作是题目描述中三种中的一种。
//输出
//如果操作为push，则不输出任何东西。
//如果为另外两种，若栈为空，则输出 "error“
//否则按对应操作输出。
//输入输出样例
//输入
//6
//push 1
//pop
//top
//push 2
//push 3
//pop
//输出
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
}//入栈且计算分数并返回分数
Status Pop(SqStack& s) {
	if (s.top == s.base)
		printf("error\n");
	else {
		printf("%d\n", *(s.top - 1));
		s.top--;
	}
	return OK;
}//出栈
Status GetTop(SqStack& s) {
	if (s.top == s.base)
		printf("error\n");
	else
		printf("%d\n",* (s.top - 1));
	return OK;
}//获取栈顶元素

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