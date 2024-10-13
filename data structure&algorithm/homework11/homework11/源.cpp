//1: 回文链表
//“回文”指正读反读均相同的字符序列，如“abcdcba”和“abba”均是回文，使用栈这种数据结构判断给定字符序列是否为回文，要求使用链栈实现。
//输入
//一个字符序列，字符序列长度≤1000
//输出
//输出为true / false，分别表示输入的字符序列是否为回文
//样例
//输入  abcda
//输出  false
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include "math.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);//创建链表
int CompareList(LinkList L);//加出孪生和

int main(void) {
	LinkList head = CreatList();
	int Ans = CompareList(head);
	if (Ans == 0) {
		printf("false");
	}
	else printf("true");
}

LinkList CreatList(void) {
	LinkList head = new LNode;
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	char e;
	while (1) {
		e = getchar();
		if (e == '\n') break;//判断结束
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return head;
}
int CompareList(LinkList L) {
	int n = 0;
	int ans = 1;
	LinkList p = L;
	while (p->next) {
		n++;
		p = p->next;//一共n个节点
	}
	int b = floor(n / 2);
	p = L->next;
	while (b) {
		LinkList r = L->next;
		while (r->next->next)
		{
			r = r->next;
		}//r指向倒数第二个
		if (r->next->val != p->val) {
			ans = 0;
		}
		r->next = NULL;
		p = p->next;
		b--;
	}
	return ans;
}