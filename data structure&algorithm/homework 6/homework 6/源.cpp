//6: 合并两个链表
//给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
//请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。
//3 <= list1.length <= 10 ^ 4
//1 <= a <= b < list1.length - 1
//	1 <= list2.length <= 10 ^ 4
//	- 1作为链表结束符
//	输出链表
//	输入样例
//	0 1 2 3 4 5 - 1
//	3
//	4
//	1000000 1000001 1000002 - 1
//	输出样例
//	0 1 2 1000000 1000001 1000002 5
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
LinkList DeleteList(LinkList L,int a,int b);//删除部分节点
LinkList AddList(LinkList L1, LinkList L2,int a);//合并
void PrintList(LinkList L);

int main(void) {
	LinkList head1 = CreatList();
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	LinkList head2 = CreatList();
	DeleteList(head1,a,b);
	AddList(head1, head2,a);
	PrintList(head1);
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
LinkList DeleteList(LinkList L, int a, int b) {
	LinkList q = L;
	int c = b - a+1;
	while (a)
	{
		q = q->next;//需删除q->next
		a--;
	}
	while (c) {
		q->next = q->next->next;
		c--;
	}
	return L;
}
LinkList AddList(LinkList L1, LinkList L2,int a) {
	LinkList q=L1;
	LinkList p = L2->next;
	while (a)
	{
		q = q->next;//接在q后面
		a--;
	}
	while (p->next)
	{
		p = p->next;//遍历到尾端
	}
	p->next = q->next;
	q->next = L2->next;
	return L1;
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