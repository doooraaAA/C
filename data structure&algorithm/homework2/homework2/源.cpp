
//2: 删除排序链表中的重复元素
//描述
//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回已排序的链表
//输入
//输入已排序的链表，链表中节点数目在范围[0, 300] 内， - 100 <= Node.val <= 100，题目数据保证链表已经按升序排列
//- 1表示链表结束符
//输出
//输出已排序的链表
//输入样例
//1 1 2 3 3 - 1
//输出样例
//1 2 3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct LNode {
	int val=-333;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //用尾插法建立带头结点的单链表
LinkList DeleteList(LinkList L);    //删除重复值的结点,并返回
void Printlist(LinkList L);//打印结果
int main(void) {
	LinkList head = CreatList();
	DeleteList(head);
	Printlist(head);
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
LinkList DeleteList(LinkList L) {
	LinkList p = L;
	while (p->next) {
		if (p->next->val == p->val) p->next = p->next->next;
		else p = p->next;
	}
	return L;
}
void Printlist(LinkList L) {
	LinkList p;
	p = L->next;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
}