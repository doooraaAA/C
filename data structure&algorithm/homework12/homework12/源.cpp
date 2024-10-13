//2: 入栈与出栈
//给定一个正整数数列（以0表示输入结束），从第一个数开始，将每一个数入栈，入栈的同时获得一个分数，即该数的数值乘以入栈后栈的大小，请计算将所有元素入栈后的分数和，然后将栈内元素依次输出，要求使用顺序栈。元素个数 < 100，每个元素 < 100。
//	输入
//	一行，一个正整数数列，以0结尾。
//	输出
//	两行，第一行为一个正整数，表示分数和。
//	第二行为将所有元素出栈后的结果，空格分隔
//	输入输出样例
//	输入	5 4 3 2 1 0
//	输出	35	1 2 3 4 5
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
}//入栈且计算分数并返回分数
Status Pop(SqStack& s) {
	if (s.top == s.base)
		return ERROR;
	s.top--;
	return OK;
}//出栈
Status GetTop(SqStack& s) {
	if (s.top != s.base)
		return *(s.top - 1);
}//获取栈顶元素

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