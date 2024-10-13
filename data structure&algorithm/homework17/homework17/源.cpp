//7: 栈的压入、弹出序列
//对输入的两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。
//栈中数据的数量≤1000
//2. push 的所有数字均不相同
//输入
//输入为两行，每行包括一个数字序列，用空格隔开， - 1结束。两个数字序列分别表示栈的压入顺序与弹出顺序
//输出
//输出为true / false表示第二个序列能否为该栈的弹出顺序
//输入输出样例
//输入
//1 2 3 4 5 - 1
//4 5 3 2 1 - 1
//输出
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
}//初始化
Status Push(SqStack& s, int e) {
	if (s.top - s.base == s.stacksize)
		return OVERFLOW;
	*s.top = e;
	s.top++;
	return OK;
}//入栈
Status Pop(SqStack& s) {
	if (s.top != s.base)
	s.top--;
	return OK;
}//出栈
Status GetTop(SqStack& s) {
	if (s.top != s.base)
		return *(s.top - 1);
	else return -1;
}//获取栈顶元素

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
	b = a - 1;//b为长度
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