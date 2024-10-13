//7: 反转链表Ⅱ
//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
///链表中节点数目为 n
//1 <= n <= 500
//- 500 <= Node.val <= 500
//1 <= left <= right <= n
//- 1表示链表结束符
//输出链表
//输入样例
//1 2 3 4 5 - 1 2 4
//输出样例
//1 4 3 2 5
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
LinkList SwitchList(LinkList L, int a, int b);//转化部分节点
void PrintList(LinkList L);

int main(void) {
	LinkList head = CreatList();
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	SwitchList(head, a, b);
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
LinkList SwitchList(LinkList L, int a, int b) {
	LinkList q = L;
	int c = b - a + 1;
	LinkList head = new LNode;
	head->next = NULL;
	while (a-1)
	{
		a = a - 1;
		q = q->next;//从q->next修改
	}
	while (c) {//头插法创立新链表
		LinkList r=new LNode;
 		r->val = q->next->val;
		r->next = head->next;
		head->next = r;
		q->next = q->next->next;
		c--;
	}
	LinkList s = head;
	while (s->next)
	{
		s = s->next;
	}
	s->next = q->next;
	q->next = head->next;
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
