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
int Compare(LinkList L);
int main(void) {
	int n;
	scanf("%d", &n);
	LinkList head = CreatList(n);
	int ans = Compare(head);
	printf("%d", ans);
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
int Compare(LinkList L) {
	LinkList p = L->next;
	int a = p->val;
	int b = p->val;
	while (p)
	{
		if (a > p->val)  a = p->val;
		if (b < p->val) b = p->val;
		p = p->next;
	}
	return b-a;
}