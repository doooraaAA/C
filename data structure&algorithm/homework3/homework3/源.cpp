//3: 从尾到头打印链表
//描述
//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
//输入链表，0 <= 链表长度 <= 10000
//- 1表示链表结束符
//输出反转后的链表
//输入样例
//1 2 6 3 4 5 6 - 1
//输出样例
//6 5 4 3 6 2 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //用尾插法建立带头结点的单链表
LinkList SwitchList(LinkList L);//头尾转换
void Printlist(LinkList L);//打印结果
int main(void) {
	LinkList head = CreatList();
	LinkList P= SwitchList(head);
	Printlist(P);
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
LinkList SwitchList(LinkList L)
{
	LinkList P = new LNode;
	P->next = NULL;
	LinkList r, q;
	r = P;
	q = L->next;
	while (q)
	{
		LinkList s = new LNode;
		s->next =r->next;
		s->val = q->val;
		r->next = s;
		q = q->next;
	}
	return P;
}
void Printlist(LinkList L) {
	LinkList p;
	p = L->next;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
}
