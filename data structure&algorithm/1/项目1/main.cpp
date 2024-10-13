//描述
//给你一个链表的头节点 head 和一个整数val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点
//输入
//输入链表和val，列表中的节点数目在范围 [0, 10^4] 内，1 <= Node.val <= 50，0 <= val <= 50
//-1表示链表结束符
//输出
//输出移除元素的链表
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
typedef struct LNode {
	int val;
	struct LNode *next;
} LNode, *LinkList;

LinkList CreatList(void);            //用尾插法建立带头结点的单链表
LinkList DeleteList(LinkList L, int val);    //删除指定值的结点,并返回
void Printlist(LinkList L);//打印结果

int main() {
	LinkList head = CreatList();
	int val;
	scanf("%d", &val);
	DeleteList(head, val);
	Printlist(head);
}

LinkList CreatList(void) {
	LinkList head = (LinkList)malloc(sizeof(LNode));
	LinkList q;
	q = new LNode;
	head->next = NULL;
	q = head;
	int e;
	while (1) {
		scanf("%d", &e);
		if (e < 0 || e > 50) {
			break;//判断输入是否合法，不合法则不放入链表
		}
		LinkList p;
		p = new LNode;
		p->val = e;
		p->next = NULL;
		q->next = p;
		q = p;;
	}
	return head;
}

LinkList DeleteList(LinkList L, int val) {
	if (L->next == NULL) {
		return 0;//链表为空
	}
	LinkList p = L;
	LinkList q;
	while (1) {
		if (p == NULL) {
			break;//遍历结束
		}
		if (p->next->val == val) {
			q = new LNode;
			q = p->next;
			p->next = q->next;
			delete q;//指向下下个节点并释放临时储存结点
		}//相等则删除
		p = p->next;
	}
	return L;
}
void Printlist(LinkList L) {
	LinkList p;
	p = L;
	while (p) {	
		printf("%d", p->val);	
		p = p->next;
	}
}
