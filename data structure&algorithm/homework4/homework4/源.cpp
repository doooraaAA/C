//4: 二进制链表转整数
//给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是1。已知此链表是一个整数数字的二进制表示形式。请你返回该链表所表示数字的 十进制值
//输入链表，链表不为空。链表的结点总数不超过 30。每个结点的值不是 0 就是 1。
//- 1表示链表结束符
//输出十进制数
//输入样例
//1 0 1 - 1
//输出样例
//5
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"math.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //用头插法建立带头结点的单链表
int Switch(LinkList L);//进制转换

int main(void) {
	LinkList head = CreatList();
	int ans = Switch(head);
	printf("%d", ans);
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
		p->next = q->next;
		q->next = p;
	}
	return head;
}
int Switch(LinkList L)
{
	int ans = 0;
	int i = 0;
	LinkList p = L->next;
	while (p) {
		int e = p->val;
		ans = e * pow(2, i)+ans;
		p = p->next;
		i = i + 1;
	}
	return ans;
}