//����һ��ֻ���� ��(�� �� ��)�� ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ���
//����Ϊһ��ֻ���� ��(�� �� ��)�� ���ַ������ַ������� < 10000��
//���
//���Ϊһ�����֣���ʾ���Ч�����Ӵ��ĳ���
//����
//(()
//���
//2
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
	s.base = new int[10000];
	if (!s.base) return OVERFLOW;
	s.top = s.base;
	s.stacksize = 10000;
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
int GetTop(SqStack& s) {
	if (s.top != s.base)
		return *(s.top - 1);
	else return -1;//ջ��ʱ����\n
}//��ȡջ��Ԫ��

//char str[10010];
//int main(void) {
//	SqStack S1,S2;//S1����ȫ����S2�ģ�ƥ��
//	Init(S1);
//	Init(S2);
//	int a = 0;
//	char b = 0;
//	while (1)
//	{
//		scanf("%c", &b);
//		str[a] = b;
//		if (b == '\n')break;
//		a++;
//	}
//	int i = 0;
//	while (1) {
//		if (str[i] == '\n') break;
//		Push(S1, str[i]);
//		i++;//ѹ��ջ
//	}
//	int ans=0;
//	int tag = 0;
//	int m = 0;
//	int n = 0;
//	while (GetTop(S1)!=-1)//ջ�ǿգ���ȥ��ߣ�������ջ
//	{
//		if (GetTop(S1) == ')') {
//			m =  m+1;
//			Push(S2, GetTop(S1));
//			Pop(S1);
//			if (GetTop(S1) == ')' && GetTop(S2) == ')')
//				n= 1 + n;
//		}
//		if (GetTop(S1) == '(' && GetTop(S2) == ')') {
//			m = m - 1;
//			tag = 1+tag;
//			Pop(S1);
//			Pop(S2);
//			if (ans < 2 * tag) ans = 2 * tag;
//		}
//		if (GetTop(S1) == '(' && GetTop(S2) == -1) {
//			Pop(S1);
//			tag = 0;
//		}
//	}
//	if (m != 0) ans = ans - 2 * (m-(n-1));
//	printf("%d", ans);
//}
int longestValidParentheses(char* s) {
    int count = 0;
    int sum = 0;
    int validnum = 0;
    int max = 0;

    while (*s != '\0')
    {
        count++;
        if (*s == '(')
            sum++;
        else
            sum--;
        if (sum < 0)
        {
            sum = 0;
            *s = 'b';
        }
        s++;
    }
    s--;
    for (sum = 0; count > 0; count--, s--)
    {
        if (*s == 'b')
        {
            max = (max > validnum) ? max : validnum;
            validnum = 0;
            continue;
        }
        else if (*s == '(')
            sum++;
        else if (*s == ')')
            sum--;
        if (sum > 0)
        {
            sum = 0;
            *s = 'b';
            max = (max > validnum) ? max : validnum;
            validnum = 0;
        }
        else
            validnum++;
    }
    max = (max > validnum) ? max : validnum;
    return max;
}