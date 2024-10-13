//8: 删除链表的倒数第 N 个结点
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//输入链表和要删除的n ，链表中结点的数目为 sz，
//1 <= sz <= 30，0 <= Node.val <= 100，1 <= n <= sz
//- 1表示链表结束符
//输出链表
//输入样例
//1 2 3 4 5 - 1
//2
//输出样例
//1 2 3 5
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //用尾插法建立带头结点的单链表
LinkList DeleteList(LinkList L, int n);//删除部分节点
void PrintList(LinkList L);

int main(void) {
	LinkList head = CreatList();
	int n;
	scanf("%d", &n);
	DeleteList(head, n);
	PrintList(head);
}

LinkList CreatList(void) {
	LinkList head = new LNode;
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	int e;
	while (1) {
		scanf("%d", &e);
		if (e == -1) break;//判断结束
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;
	}
	return head;
}
LinkList DeleteList(LinkList L, int n) {
	int a = 0;
	LinkList p = L;
	LinkList q = L;
	while (p->next) {
		p = p->next;
		a++;
	}
	int c = a - n;
	while (c) {
		q = q->next;
		c--;
	}
	q->next = q->next->next;
	return L;
}

void PrintList(LinkList L) {
	LinkList q;
	q = L->next;
	while (q)
	{
		printf("%d ", q->val);
		q = q->next;
	}
}