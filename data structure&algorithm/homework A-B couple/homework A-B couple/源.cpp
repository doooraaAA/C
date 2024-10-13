//4: A - B数对
//描述
//给出一串单调不下降的数以及一个数字 C，要求计算出所有A−B = C 的数对的个数（不同位置的数字一样的数对算不同的数对）
//输入
//输入共两行。
//第一行，两个整数 N, C。
//第二行，N个整数，作为要求处理的那串数。
//输出
//一行，表示该串数中包含的满足A−B = C 的数对的个数。
//输入
//4 1
//1 1 2 3
//输出
//3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(int n);            //用尾插法建立带头结点的单链表
int Lookout(LinkList L, int e);
int main(void) {
	int N, C;
	scanf("%d %d", &N, &C);
	LinkList head = CreatList(N);
	int ans = Lookout(head, C);
	printf("%d ", ans);
	return 0;
}

LinkList CreatList(int n) {
	LinkList head = new LNode;
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	int e;
	while (n) {
		scanf("%d", &e);
		n--;
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return head;
}
int Lookout(LinkList L, int C) {
	LinkList p = L->next;	
	int count = 0;
	while (p)
	{
		LinkList r = L->next;
		while (r) {
			if (p->val - r->val == C) count++;
			r = r->next;
		}
		p = p->next;
	}
	return count;
}