//9: 重排链表
//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//L0 → L1 → … → Ln - 1 → Ln
//请将其重新排列后变为：
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//输入链表的长度范围为[1, 5 * 10 ^ 4]
//1 <= node.val <= 1000
//- 1表示链表结束符
//输出重排链表
//输入样例
//1 2 3 4 5 - 1
//输出样例
//1 5 2 4 3
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"stdio.h"
#include"string.h"
#include"ctype.h"
#include<math.h>
typedef struct LNode {
	int val;
	struct LNode* next;
} LNode, * LinkList;

LinkList CreatList(void);            //用尾插法建立带头结点的单链表
LinkList SwitchList(LinkList L);//删除部分节点
void PrintList(LinkList L);

int main(void) {
	LinkList head = CreatList();
 	SwitchList(head);
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
LinkList SwitchList(LinkList L) {
	int len = 0;
	LinkList p = L;
	while (p->next) {
		len++;
		p = p->next;//一共len个节点
	}
	int b = floor((len-1)/ 2);
	p = L->next;
	while(b){
		LinkList r = L->next;
		while (r->next->next)
		{
			r = r->next;
		}//r指向倒数第二个
		r->next->next = p->next;
		p->next = r->next;
		r->next = NULL;
		p = p->next->next;
		b--;//永远将倒数第二个插入到p的下一个
	}
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
